/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/

namespace Phady\Mail;

/**
  * @class Phady\Mail\MailReader - This class is used to read and analyze IMAP mailboxes with features such as :
  * - Used to access plain text, html , headers and attachments of messages
  * - Read Message by date of receipt by the sender address messages .
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Mail
  * @copyright (c) 2015
  * @version 1.0.0
  */
class MailReader
{
   /**
    * Mail server to connect
    *
    * @var string
    */
   private mailserver = "";

   /**
    * User mail server ej. xyz.abc@mail.com
    *
    * @var string
    */
   private username = "";

   /**
    * User Password mail server
    *
    * @var string
    */
   private password;

    /**
     * Port connection to the mail server
     *
     * @var integer
     */
    private port;

    /**
     * Mailbox user input
     *
     * @var string
     */
    private mailbox = "";

    /**
     * Conexion al servidor de correo
     *
     * @var resource IMAP stream as a connection
     */
    private connection = null;

    /**
     * Contains items from header information
     *
     * @var Object
     */
    private headers;

    /**
     * Associative array containing the attachment name as a key and the corresponding binary file as value.
     *
     * @var Array
     */
    private attachments = [];

    /**
     * This variable contains the HTML part of a message .
     *
     * @var String
     */
    private htmlBody = "";

    /**
     * Contains the plain text part of a message.
     *
     * @var String
     */
    private plainBody = "";

    /**
     * Associative array containing attachments, HTMLBody , plainBody as their keys.
     * 
     * @var Array
     */
    private result = [];

    /**
     * Constant Connection Port mail server ssl
     *
     * @var integer
     */
    const IMAP_PORT_SSL = 993;

    /**
     * Use constant ssl
     *
     * @var bool
     */
    const USE_SSL = true;

    /**
     * Constant Use ssl certificate no
     *
     * @var bool
     */
    const USE_NOVALIDATE_CERT_SSL = false;

    /**
     * Constant Try connecting the mail server three times
     *
     * @var bool
     */
    const TRY_TO_CONNECT = 3;

    /**
     * Option unread message
     *
     * @var bool
     */
    const UNREAD = 4;

    /**
     * Constant type of mail server
     *
     * @var string
     */
    const DEFAULT_SERVER_TYPE = "imap";

    /**
     * Constructor de la clase MailReader
     *
     * @param String username
     * @param String password
     * @param String mailserver
     * @param Array options - Array de opciones
     *                  ["serverType"] - Type access server messages stored on an Internet server ej. "imap" o "pop".
     *                  ["useSSL"] - If you are using secure communication with the server.
     *                  ["useNoValidateCertSSL"] - If the server does not have a valid certificate.
     *                  ["port"] - Port for communication with server.
     */
    public function __construct(string! username, string! password, string! mailserver = "imap.gmail.com", var options = []) {
        var serverType, useSSL, useNoValidateCertSSL, port, strConnect;
        let serverType = (array_key_exists("serverType", options)) ? options["serverType"] : self::DEFAULT_SERVER_TYPE;
        let useSSL = (array_key_exists("useSSL", options)) ? options["useSSL"] : self::USE_SSL;
        let useNoValidateCertSSL = (array_key_exists("useNoValidateCertSSL", options) && !empty(options["useNoValidateCertSSL"])) ? options["useNoValidateCertSSL"] : self::USE_NOVALIDATE_CERT_SSL;
        let port = (array_key_exists("port", options)) ? options["port"] : self::IMAP_PORT_SSL;
        //print_r(options);die;
        if (serverType == self::DEFAULT_SERVER_TYPE) {
            if (useSSL) {
                let this->port = self::IMAP_PORT_SSL;
                //useNoValidateCertSSL
                let strConnect = "{" . mailserver . ":" . this->port . "/imap/ssl";
                if (useNoValidateCertSSL) {
                    let strConnect .= "/novalidate-cert}";
                } else {
                    let strConnect .= "}";
                }
            } else {
                let this->port = "143";
                let strConnect = "{" . mailserver . ":" . this->port . "/novalidate-cert}";
            }
        } else {
            let strConnect = "{" . mailserver . ":" . port . "/pop3/novalidate-cert}";
            let this->port = port;
        }
        //Parametro del servidor y usuario
        let this->mailbox = strConnect;
        let this->mailserver = mailserver;
        let this->username = username;
        let this->password = password;
        //Establecer la conexion
        this->setConnection();
    }
    
    /**
     * Function to connect to the specified email server .
     *
     * @return IMAP stream as a connection
     */
    public function setConnection() {
        var key, exception;
        // If the connection does not exist a connection is established
        if (!this->connection) {
            // If the folder name is not present INBOX
            if (substr(trim(this->mailbox), -1) == "}") {
                let this->mailbox = this->mailbox . "INBOX";
            }
            //print_r(this->mailbox);die;
            try {
                //Try to connect three times
                for key in range(1, self::TRY_TO_CONNECT){
                    if function_exists("imap_open") {
                        let this->connection = imap_open(this->mailbox, this->username, this->password);
                    } else {
                        throw new \Exception("imap_open function is not available install the extension php5_imap");
                    }
                    if (this->connection) {
                        return this->connection;
                    }
                }
                // exceptions can be thrown here
                throw new \Exception("You can't connect the mail server");
            } catch \Exception, exception {
                // handle exception
                echo exception->getMessage();
                exit();
            }
        }
    }

    /**
     * Function to read messages and filter user
     *
     * @param Integer userInput
     * @param Integer filterType
     * @param Boolean flag
     */
    public function readMessageByFilter(int userInput, int filterType, boolean flag) {
        var i, countMsg, filter;
        let countMsg = imap_num_msg(this->connection);
        //print_r(countMsg);die;
        // Iteration on mailbox messages
        for i in range(1, countMsg){
            let this->headers = imap_headerinfo(this->connection, i);
            //print_r(this->headers);die;
            // Preparing filter by given filter type
            if (filterType == 0) {
                let filter = this->headers && (this->headers->Msgno == trim(userInput));
            } elseif (filterType == 1) {
                let filter = this->headers && (this->getRecDate(this->headers->date) == trim(userInput));
            } elseif (filterType == 2) {
                let filter = this->headers && (this->headers->Subject == trim(userInput));
            } elseif (filterType == 3) {
                let filter = this->headers && (this->containsFromAddress(this->headers->fromaddress, trim(userInput)));
            } elseif (filterType == 4) {
                let filter = this->headers && true;
            }
            //print_r(filter);die;
            // Process only filtered messages by received date
            if (filter) {
                if (flag) {
                    if (this->headers->Unseen == "U"){
                        this->parseMessage(i);
                    }
                }
                else {
                    this->parseMessage(i);
                }
            }
        }
        imap_close(this->connection);
        //print_r(this->result);die;
        return this->result;
    }

    /**
     * Date Posted format dd-mm-aaaa
     *
     * @param String date format Thu, 20 Aug 2009 15:55:52 +0530
     * @return String date format 08-20-2009
     */
    private function getRecDate(string date) {
        var timestamp;
        let date = substr(date, 5, 20);
        let timestamp = strtotime(date);
        return date("m-d-Y", timestamp);
    }

    /**
     * This function is used to check the email id in particular present
     * The address of the header information . Returns true if present , otherwise false.
     *
     * @param String fromAddresses
     * @param String userInput
     * @return bool
     */
    private function containsFromAddress(string! fromAddresses, string! userInput) {

        if (strpos(fromAddresses, userInput) != false) {
            return true;
        }
        return false;
    }

    /**
     * Function to get the message
     *
     * @param Integer messageId
     */
    public function getMessage(int messageId) {
        var structure, arrParts;
        let structure = imap_fetchstructure(this->connection, messageId);
        //print_r(structure);die;
        // If message is not multipart
        let arrParts = [];
        let arrParts = structure->parts;
        // If message is not multipart
        if (empty(arrParts)) {
            this->getMessagePart(messageId, structure, 0);
        } elseif (is_array(arrParts)) {
            var partMsg, key;
            for key, partMsg in arrParts {
                this->getMessagePart(messageId, partMsg, key + 1);
            }
        }
    }

    /**
     * Function to parse the message parts
     *
     * @param Integer messageId
     * @param Object partObj
     * @param Integer partno
     */
    public function getMessagePart(int messageId, var partObj, int partno) {
        var data, params, x, y, filename, partno2, part2, partNoAll, part2Length;
        // If partno is 0 then fetch body as a single part message
        let data = (partno) ? imap_fetchbody(this->connection, messageId, partno) : imap_body(this->connection, messageId);
        //print_r(data);die;

        // Any part may be encoded, even plain text messages, so decoding it
        if (property_exists(partObj, "encoding") && partObj->encoding == 4) {
            let data = quoted_printable_decode(data);
        } elseif (property_exists(partObj, "encoding") && partObj->encoding == 3) {
            let data = base64_decode(data);
        }

        // Collection all parameters, like name, filenames of attachments, etc.
        let params = [];
        if (property_exists(partObj, "parameters") && partObj->parameters) {
            for x in (array) partObj->parameters {
                let params[strtolower(x->attribute)] = x->value;
            }
        }
        if (property_exists(partObj, "dparameters") && !empty(partObj->dparameters)) {
            for y in (array) partObj->dparameters {
                let params[strtolower(y->attribute)] = y->value;
            }
        }

        // Any part with a filename is an attachment,
        if ((array_key_exists("filename", params) || array_key_exists("name", params)) && (params["filename"] || params["name"])) {
            // Filename may be given as "Filename" or "Name" or both
            let filename = (array_key_exists("filename", params) && params["filename"]) ? params["filename"] : params["name"];
            let this->attachments[filename] = data;
        }

        // Processing plain text message
        if (partObj->type == 0 && data) {
            // Messages may be split in different parts because of inline attachments,
            // so append parts together with blank row.
            if (strtolower(partObj->subtype) == "plain") {
                let this->plainBody .= trim(data);
            } else {
                //this->htmlBody .= data;
            }
        }

        // Some times it happens that one message embeded in another.
        // This is used to appends the raw source to the main message.
        elseif (partObj->type == 2 && data) {
            let this->plainBody .= trim(data);
        }

        // Here is recursive call for subpart of the message
        if (property_exists(partObj, "parts") && !empty(partObj->parts)) {
            for partno2, part2 in (array) partObj->parts {
                let part2Length = strlen(partno2 + 1);
                let partNoAll = partno * part2Length + (partno2 + 1);
                this->getMessagePart(messageId, part2, partNoAll);
            }
        }
    }

    /**
     * Function to parse the message
     *
     * @param Integer messageId
     */
    public function parseMessage(int messageId) {
        this->getMessage(messageId);
        this->makeResult();
    }

    /**
     * Prepare message as array
     *
     */
    private function makeResult() {
        var msg;

        let msg = [];
        //msg['attachments'] = this->attachments;
        //msg['htmlBody'] = this->htmlBody;
        let msg["Mensaje"] = this->plainBody;
        let msg["headers"] = this->headers;

        let this->result[] = msg;
        //print_r(this->result);die;
        // Eliminando variables para el siguiente mensaje
        let this->attachments = [];
        let this->plainBody = "";
        unset(this->headers); //, this->htmlBody, this->attachments, this->plainBody,
    }

    /**
     * Function to parse the messages that have not yet been read .
     *
     */
    public function getUnreadMessages() {
        this->readMessageByFilter(0, self::UNREAD, true);
    }
}

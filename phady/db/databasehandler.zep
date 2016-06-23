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

namespace Phady\Db;

//use Phalcon\Db\Adapter\Pdo\Postgresql as PostgresqlAdapter;
use Phalcon\Db\Adapter\Pdo\Mysql as MysqlAdapter;
//use Phalcon\Db\Adapter\Pdo\Sqlite as SqliteAdapter;
//use Phalcon\Db\Adapter\Pdo\Oracle as OracleAdapter;

/**
  * @class Phady\Db\DatabaseHandler -  Database handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
final class DatabaseHandler
{

    /**
     * @var array config - Config database
     */
    protected config;

    /**
     * @param array config - Config db
     */
    public function __construct(array! config) {
        //Read config file
        let this->config = config;
    }

    /**
     *
     * @return DBAdapter Adaptador de base de datos 
     */
    public function getAdapter() {
        var arrdbConfig, dbConfig, adapter;
        let dbConfig = this->config["orm"]["database"];
        
        let arrdbConfig = [
            "host" : dbConfig["host"],
            "username" : dbConfig["username"],
            "password" : dbConfig["password"],
            "dbname" : dbConfig["dbname"]
        ];
        //echo "<pre>"; print_r(arrdbConfig); die();

        switch dbConfig["driver"] {
            case "mysql":
                let adapter = new MysqlAdapter(arrdbConfig);
                break;

            case "pgsql":
                let adapter = new PostgresqlAdapter(arrdbConfig);
                break;
            case "sqlite":
                let adapter = new SqliteAdapter(arrdbConfig);
                break;
            case "oracle":
                let adapter = new OracleAdapter(arrdbConfig);
                break;
            default :
                let adapter = new MysqlAdapter(arrdbConfig);
                break;
        }
        return adapter;
    }
}

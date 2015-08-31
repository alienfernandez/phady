
namespace Phady\Config;

/**
 * Phady\Config\Yaml
 *
 * Reads YAML files and converts them to Phady\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 * phady
 *   baseuri: /phady/
 * models:
 *   metadata: memory
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phady\Config\Yaml();
 * $config->parse("path/config.yaml")
 * echo $config->phady->baseuri;
 * echo $config->models->metadata;
 *</code>
 *
 */
class Yaml
{

	/**
	 * Phady\Config\Yaml constructor
	 *
	 * @param  string                    $filePath
	 * @param  array                     $callbacks
	 * @throws \Phady\Exception
	 */
    public static function parse(string! filePath, array! callbacks = null)
    {
        var yamlConfig;
        if !extension_loaded("yaml") {
			throw new \Phady\Exception("Yaml extension not loaded");
		}
		int ndocs = 0;

		if callbacks !== null {
			let yamlConfig = yaml_parse_file(filePath, 0, ndocs, callbacks);
		} else {
			let yamlConfig = yaml_parse_file(filePath);
		}

		if yamlConfig === false {
			throw new \Phady\Exception("Configuration file " . basename(filePath) . " can't be loaded");
		}

		return yamlConfig;
    }
}
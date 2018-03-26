## Phady Framework

Phady Framework is a web framework based on Phalcon framework, it extends some Phalcon classes written in Zephir language to provide additional functionality.
With the Phady Dev-Tools you can have a good completion of code, it is located in https://github.com/alienfernandez/phady-devtools and you need install to your favorite IDE

##Currently it provides classes for:

- Caching
- Configuration reading
- Kernel classes for Web MVC and console applications
- Database access adapters
- HTTP request processing
- Email retrieving
- Message queuing
- Request routing
- Multiple security aspect handling
- Miscellaneous utilities

##Example how you run the application with Phady Framework:
```php
use Phady\Core\KernelMvc;
try {
    $modules = [[
        "common" => ["className" => "App\Common\Module", "path" => __DIR__ . "/../src/common/Module.php"]
       ]
    ];
    $environment = "dev"; //dev or prod
    $mode = "mvc"; //mvc or cli
    $appCore = new KernelMvc($environment, false, "mvc", $modules);
    //Handle the request
    echo $appCore->getApplication()->handle()->getContent();
} catch (Phalcon\Exception $e) {
    echo $e->getMessage();
} catch (PDOException $e) {
    echo $e->getMessage();
}

```

### License


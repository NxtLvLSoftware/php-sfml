PHP-SFML
===================
__SFML (Simple and Fast Multimedia Library) bindings for the php language.__

### Requirements

* C compiler
* Automake tools
* libsfml v2 libraries and headers
* UN*X OS (eg Linux, Macos)

Building
========

To compile your new extension, you will have to execute the following steps:

```bash
$ phpize
$ ./configure [--enable--sfml] 
$ make
$ make test
$ [sudo] make install
```

Then add 

```
extension=sfml.so
```
to your _php.ini_ file.

## Documentation

The SFML extension aims to mimic almost every single aspect of the official C++ library, so until we write our own documentation,
refer to the [C++ counterpart](https://www.sfml-dev.org/documentation/).

### Example

Currently the only bindings available are for the SFML version consts/defines:

```php
echo sprintf("Using SFML v%d.%d.%d", SFML_VERSION_MAJOR, SFML_VERSION_MINOR, SFML_VERSION_PATCH) . PHP_EOL;
```

### Developing
If you're using an IDE like PHPStorm you can add the [stubs directory](/stubs) to your include path for auto-completion.

## Support and feature requests
Please submit anything that requires our attention to our [issue tracker](https://github.com/NxtLvLSoftware/php-sfml/issues)
on Github. We will attempt to respond to sensible requests in a reasonable time frame.
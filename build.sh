#!/usr/bin/env bash

#
# This is a very simple build script, it will only build and install the
# extension against the system php and is only intended to streamline development.
#

phpize && ./configure --with-sfml && make install
make clean && phpize --clean
rm -f stubs/sfml.php && php-ext-stub --ext=sfml >> stubs/sfml.php
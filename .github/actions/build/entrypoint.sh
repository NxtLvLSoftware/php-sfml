#!/bin/sh

if [ $# -eq 0 ]; then
  sh -c "phpize && CFLAGS=\"$CFLAGS\" CXXFLAGS=\"$CXXFLAGS\" ./configure && make -j $(nproc) && make install && docker-php-ext-enable sfml && REPORT_EXIT_STATUS=1 NO_INTERACTION=1 TEST_PHP_ARGS="--show-diff" make test"
else
  exec "$@"
fi

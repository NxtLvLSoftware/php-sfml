#!/bin/sh

if [ $# -eq 0 ]; then
  sh -c "phpize && ./configure && make -j $(nproc) && make install && docker-php-ext-enable sfml && make test"
else
  exec "$@"
fi

#!/bin/sh

sh -c "phpize && ./configure && make -j $(nproc) && make test"
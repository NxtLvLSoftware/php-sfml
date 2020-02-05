#!/bin/sh

# publish the builds to docker hub
sh -c "phpize && ./configure && make -j $(nproc) && make test"
FROM php:7.3-cli
RUN apk add --no-cache sfml-dev && \
    (
        phpize && \
        ./configure --enable-sfml && \
        make -j "$(nproc)" && \
        make test \
     )
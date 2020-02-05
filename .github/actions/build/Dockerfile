FROM php:7.3-cli
RUN apt-get update && apt-get install --no-install-recommends -y libsfml-dev && \
    ( \
        phpize && \
        ./configure --enable-sfml && \
        make -j "$(nproc)" && \
        make test \
     )
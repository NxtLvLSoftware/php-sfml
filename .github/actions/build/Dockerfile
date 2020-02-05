FROM php:7.3-cli
MAINTAINER NxtLvL Software Solutions <contact@nxtlvlsoftware.net>

RUN apt-get update && apt-get install --no-install-recommends -y libsfml-dev

ADD entrypoint.sh /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
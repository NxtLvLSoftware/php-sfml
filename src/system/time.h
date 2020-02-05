//
// Created by Jack Noordhuis on 5/2/20.
//

#ifndef PHP_SFML_TIME_H
#define PHP_SFML_TIME_H

// Defines so we can use our macros in zend_util.h.
#define CLASS_TYPE sf::Time
#define CLASS_NAME Time

#include "../zend_util.h"

PHP_CLASS_METHOD(__construct);
PHP_CLASS_METHOD(asSeconds);
PHP_CLASS_METHOD(asMilliseconds);
PHP_CLASS_METHOD(asMicroseconds);
PHP_CLASS_METHOD(asMicroseconds);

PHP_CLASS_METHOD(zero);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO(ARG_INFO_NAME(seconds), sf\\Time, 0)
    ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()
PHP_FUNCTION(seconds);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO(ARG_INFO_NAME(milliseconds), sf\\Time, 0)
    ZEND_ARG_TYPE_INFO(0, seconds, IS_LONG, 0)
ZEND_END_ARG_INFO()
PHP_FUNCTION(milliseconds);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO(ARG_INFO_NAME(microseconds), sf\\Time, 0)
    ZEND_ARG_TYPE_INFO(0, seconds, IS_LONG, 0)
ZEND_END_ARG_INFO()
PHP_FUNCTION(microseconds);


PHP_MINIT_FUNCTION(sfml_system_time);

// Undefine so we can use the macros for other classes.
#undef CLASS_TYPE
#undef CLASS_NAME

#endif //PHP_SFML_TIME_H

//
// Created by Jack Noordhuis on 5/2/20.
//

#include <SFML/System/Time.hpp>

#include "./time.h"

// Defines so we can use our macros in zend_util.h.
#define CLASS_TYPE sf::Time
#define CLASS_NAME Time

PHP_CLASS_ENTRY_EX();

ZEND_BEGIN_ARG_INFO_EX(ARG_INFO_NAME(__construct), 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR) {
    zend_parse_parameters_none_throw();

    auto time = new sf::Time();

    SET_PHP_OBJECT_CONTAINER(time);
}

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(ARG_INFO_NAME(asSeconds), IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(asSeconds, ZEND_ACC_PUBLIC) {
    zend_parse_parameters_none_throw();

    RETURN_DOUBLE(FETCH_PHP_OBJECT_CONTAINER()->asSeconds());
}

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(ARG_INFO_NAME(asMilliseconds), IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(asMilliseconds, ZEND_ACC_PUBLIC) {
    zend_parse_parameters_none_throw();

    RETURN_LONG(FETCH_PHP_OBJECT_CONTAINER()->asMilliseconds());
}

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(ARG_INFO_NAME(asMicroseconds), IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(asMicroseconds, ZEND_ACC_PUBLIC) {
    zend_parse_parameters_none_throw();

    RETURN_LONG(FETCH_PHP_OBJECT_CONTAINER()->asMicroseconds());
}

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO(ARG_INFO_NAME(zero), sf\\Time, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(zero, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC) {
    zend_parse_parameters_none_throw();
    object_init_ex(return_value, Time_entry);
    FETCH_PHP_OBJECT_VAR_OTHER(new_intern, return_value);

    new_intern->container = new sf::Time(sf::Time::Zero);
}

PHP_FUNCTION(seconds) {
    double amount = 0;

    ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
        Z_PARAM_DOUBLE(amount)
    ZEND_PARSE_PARAMETERS_END();
    object_init_ex(return_value, Time_entry);
    FETCH_PHP_OBJECT_VAR_OTHER(new_intern, return_value);

    new_intern->container = new sf::Time(sf::seconds((float) amount));
}

PHP_FUNCTION(milliseconds) {
    zend_long amount = 0;

    ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
            Z_PARAM_LONG(amount)
    ZEND_PARSE_PARAMETERS_END();
    object_init_ex(return_value, Time_entry);
    FETCH_PHP_OBJECT_VAR_OTHER(new_intern, return_value);

    new_intern->container = new sf::Time(sf::milliseconds(amount));
}

PHP_FUNCTION(microseconds) {
    zend_long amount = 0;

    ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
        Z_PARAM_LONG(amount)
    ZEND_PARSE_PARAMETERS_END();
    object_init_ex(return_value, Time_entry);
    FETCH_PHP_OBJECT_VAR_OTHER(new_intern, return_value);

    new_intern->container = new sf::Time(sf::microseconds(amount));
}

PHP_MINIT_FUNCTION(sfml_system_time) {
    REGISTER_FUNCTION_ENTRY_START()
        REGISTER_FUNCTION_ENTRY(__construct)
        REGISTER_FUNCTION_ENTRY(asSeconds)
        REGISTER_FUNCTION_ENTRY(asMilliseconds)
        REGISTER_FUNCTION_ENTRY(asMicroseconds)

        REGISTER_FUNCTION_ENTRY(zero)
    REGISTER_FUNCTION_ENTRY_END();

    REGISTER_CLASS_WITH_HANDLERS_SET_ENTRY("sf\\Time");

    return SUCCESS;
}

// Undefine so we can use the macros for other classes.
#undef CLASS_TYPE
#undef CLASS_NAME
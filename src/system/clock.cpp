//
// Created by Jack Noordhuis on 5/2/20.
//

#include <SFML/System/Clock.hpp>

#include "clock.h"

// Defines so we can use our macros in zend_util.h.
#define CLASS_TYPE sf::Clock
#define CLASS_NAME Clock

EXTERN_PHP_CLASS_ENTRY(Time);

PHP_CLASS_ENTRY_EX();

ZEND_BEGIN_ARG_INFO_EX(ARG_INFO_NAME(__construct), 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR) {
    zend_parse_parameters_none_throw();

    auto clock = new sf::Clock();

    SET_PHP_OBJECT_CONTAINER(clock);
}

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO(ARG_INFO_NAME(getElapsedTime), sf\\Time, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(getElapsedTime, ZEND_ACC_PUBLIC) {
    zend_parse_parameters_none_throw();

    FETCH_PHP_OBJECT_CONTAINER_VAR(container);

    object_init_ex(return_value, Time_entry);
    FETCH_PHP_OBJECT_VAR_OTHER_EX(sf::Time, new_intern, return_value);

    new_intern->container = new sf::Time(container->getElapsedTime());
}
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO(ARG_INFO_NAME(restart), sf\\Time, 0)
ZEND_END_ARG_INFO()

PHP_CLASS_METHOD_EX(restart, ZEND_ACC_PUBLIC) {
    zend_parse_parameters_none_throw();

    FETCH_PHP_OBJECT_CONTAINER_VAR(container);

    object_init_ex(return_value, Time_entry);
    FETCH_PHP_OBJECT_VAR_OTHER_EX(sf::Time, new_intern, return_value);

    new_intern->container = new sf::Time(container->restart());
}

PHP_MINIT_FUNCTION(sfml_system_clock) {
    REGISTER_FUNCTION_ENTRY_START()
        REGISTER_FUNCTION_ENTRY(__construct)
        REGISTER_FUNCTION_ENTRY(getElapsedTime)
        REGISTER_FUNCTION_ENTRY(restart)
    REGISTER_FUNCTION_ENTRY_END();

    REGISTER_CLASS_WITH_HANDLERS_SET_ENTRY("sf\\Clock");

    return SUCCESS;
}

// Undefine so we can use the macros for other classes.
#undef CLASS_TYPE
#undef CLASS_NAME
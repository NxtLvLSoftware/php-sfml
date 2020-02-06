//
// Created by Jack Noordhuis on 6/2/20.
//

#include <SFML/System/InputStream.hpp>

#include "input_stream.h"

// Defines so we can use our macros in zend_util.h.
#define CLASS_NAME InputStream

PHP_CLASS_ENTRY();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(ARG_INFO_NAME(read), 0, 2, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(1, data, IS_STRING, 1)
    ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(ARG_INFO_NAME(seek), 0, 1, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(ARG_INFO_NAME(tell), 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(ARG_INFO_NAME(getSize), 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_MINIT_FUNCTION(sfml_system_input_stream) {
    REGISTER_FUNCTION_ENTRY_START()
        REGISTER_INTERFACE_FUNCTION_ENTRY(read)
        REGISTER_INTERFACE_FUNCTION_ENTRY(seek)
        REGISTER_INTERFACE_FUNCTION_ENTRY(tell)
        REGISTER_INTERFACE_FUNCTION_ENTRY(getSize)
    REGISTER_FUNCTION_ENTRY_END();

    SIMPLE_REGISTER_INTERFACE_SET_ENTRY("sf\\InputStream");

    return SUCCESS;
}

// Undefine so we can use the macros for other classes.
#undef CLASS_TYPE
#undef CLASS_NAME

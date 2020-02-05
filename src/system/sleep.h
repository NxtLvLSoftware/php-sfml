//
// Created by Jack Noordhuis on 5/2/20.
//

#ifndef PHP_SFML_SLEEP_H
#define PHP_SFML_SLEEP_H

#include "../zend_util.h"

#define CLASS_NAME Sleep

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO(ARG_INFO_NAME(sleep), IS_VOID, 0)
    ZEND_ARG_OBJ_INFO(0, duration, sf\\Time, 0)
ZEND_END_ARG_INFO()
PHP_FUNCTION(sleep);


PHP_MINIT_FUNCTION(sfml_system_time);

#endif //PHP_SFML_SLEEP_H

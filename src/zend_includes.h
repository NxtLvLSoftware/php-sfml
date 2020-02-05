//
// Created by Jack Noordhuis on 5/2/20.
//

#ifndef PHP_SFML_ZEND_INCLUDES_H
#define PHP_SFML_ZEND_INCLUDES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "php.h"
#include "php_ini.h"
#include "SAPI.h"
#include "ext/standard/info.h"
#include "zend_exceptions.h"
#include "zend_extensions.h"

#ifdef __cplusplus
};
#endif

#define PHP_MINIT_CALL(func) PHP_MINIT(func)(INIT_FUNC_ARGS_PASSTHRU)

#endif //PHP_SFML_ZEND_INCLUDES_H

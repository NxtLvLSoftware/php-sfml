//
// Created by Jack Noordhuis on 4/2/20.
//

#ifndef PHP_SFML_PHP_SFML_H
#define PHP_SFML_PHP_SFML_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "src/zend_includes.h"

extern zend_module_entry sfml_module_entry;
#define phpext_sfml_ptr &sfml_module_entry

#define PHP_SFML_VERSION "0.0.1"

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_SFML)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif //PHP_SFML_PHP_SFML_H

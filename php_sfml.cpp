//
// Created by Jack Noordhuis on 4/2/20.
//

extern "C" {
#include "php_sfml.h" // this one has to be C always, so the engine can understand it
}

#include "src/config.h"

#define PHP_MINIT_CALL(func) PHP_MINIT(func)(INIT_FUNC_ARGS_PASSTHRU)

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(sfml)
{
    // register php things
    if(PHP_MINIT_CALL(sfml_config) == SUCCESS){
        return SUCCESS;
    }

    return FAILURE;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(sfml)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "sfml support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ PHP_MSHUTDOWN
 */
PHP_MSHUTDOWN_FUNCTION(sfml)
{
    return SUCCESS;
}
/* }}} */

/* {{{ sfml_module_entry
 */
zend_module_entry sfml_module_entry = {
        STANDARD_MODULE_HEADER,
        "sfml",				    /* Extension name */
        NULL,				                /* zend_function_entry */
        PHP_MINIT(sfml),		    /* PHP_MINIT - Module initialization */
        PHP_MSHUTDOWN(sfml),	    /* PHP_MSHUTDOWN - Module shutdown */
        NULL,				                /* PHP_RINIT - Request initialization */
        NULL,		                        /* PHP_RSHUTDOWN - Request shutdown */
        PHP_MINFO(sfml),		    /* PHP_MINFO - Module info */
        PHP_SFML_VERSION,		/* Version */
        STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SFML
extern "C"{
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sfml)
}
#endif

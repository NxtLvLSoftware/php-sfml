//
// Created by Jack Noordhuis on 6/2/20.
//

#ifndef PHP_SFML_INPUT_STREAM_H
#define PHP_SFML_INPUT_STREAM_H

// Defines so we can use our macros in zend_util.h.
#define CLASS_NAME InputStream

#include "../zend_util.h"

PHP_CLASS_METHOD(read);
PHP_CLASS_METHOD(seek);
PHP_CLASS_METHOD(tell);
PHP_CLASS_METHOD(getSize);


PHP_MINIT_FUNCTION(sfml_system_input_stream);

// Undefine so we can use the macros for other classes.
#undef CLASS_TYPE
#undef CLASS_NAME

#endif //PHP_SFML_INPUT_STREAM_H

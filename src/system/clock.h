//
// Created by Jack Noordhuis on 5/2/20.
//

#ifndef PHP_SFML_CLOCK_H
#define PHP_SFML_CLOCK_H

// Defines so we can use our macros in zend_util.h.
#define CLASS_TYPE sf::Clock
#define CLASS_NAME Clock

#include "../zend_util.h"

PHP_CLASS_METHOD(__construct);
PHP_CLASS_METHOD(getElapsedTime);
PHP_CLASS_METHOD(restart);

PHP_MINIT_FUNCTION(sfml_system_clock);

// Undefine so we can use the macros for other classes.
#undef CLASS_TYPE
#undef CLASS_NAME

#endif //PHP_SFML_CLOCK_H

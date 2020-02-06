//
// Created by Jack Noordhuis on 5/2/20.
//

#include <SFML/System/Sleep.hpp>

#include "sleep.h"

EXTERN_PHP_CLASS_ENTRY(Time);

PHP_FUNCTION(sleep) {
    zval *duration = nullptr;

    ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
            Z_PARAM_OBJECT_OF_CLASS(duration, Time_entry)
    ZEND_PARSE_PARAMETERS_END();

    FETCH_PHP_OBJECT_VAR_OTHER_EX(sf::Time, new_intern, duration);

    sf::sleep(*new_intern->container);
}
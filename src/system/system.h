//
// Created by Jack Noordhuis on 5/2/20.
//

#ifndef PHP_SFML_SYSTEM_H
#define PHP_SFML_SYSTEM_H

#include "clock.h"
#include "time.h"

PHP_MINIT_FUNCTION(sfml_system) {
    if (
            PHP_MINIT_CALL(sfml_system_clock) == SUCCESS &&
            PHP_MINIT_CALL(sfml_system_time) == SUCCESS
            ){
        return SUCCESS;
    }

    return FAILURE;
}

#endif //PHP_SFML_SYSTEM_H

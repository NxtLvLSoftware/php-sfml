# dummy cmakelists.txt file for autocompletion features in clion
cmake_minimum_required(VERSION 3.12)
project(php_sfml)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC_LIST FOLLOW_SYMLINKS *.cpp)
file(GLOB_RECURSE HEAD_FILES FOLLOW_SYMLINKS *.h)

set(PHP_SOURCE /usr/local/include/php)
include_directories(BEFORE ./ ${PHP_SOURCE} ${PHP_SOURCE}/main ${PHP_SOURCE}/sapi ${PHP_SOURCE}/TSRM ${PHP_SOURCE}/Zend)

find_package(SFML REQUIRED system window graphics network audio)

add_library(php_sfml SHARED ${SRC_LIST} ${HEAD_FILES})

target_link_libraries(php_sfml PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
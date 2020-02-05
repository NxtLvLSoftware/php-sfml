--TEST--
SFML version defines available.
--SKIPIF--
<?php
require 'test-functions.php';
--FILE--
<?php
echo SFML_VERSION_MAJOR, PHP_EOL;
echo SFML_VERSION_MINOR, PHP_EOL;
echo SFML_VERSION_PATCH, PHP_EOL;

echo sprintf("Linked SFML version is v%d.%d.%d", SFML_VERSION_MAJOR, SFML_VERSION_MINOR, SFML_VERSION_PATCH), PHP_EOL;
--EXPECTF--
%d
%d
%d
Linked SFML version is v%d.%d.%d
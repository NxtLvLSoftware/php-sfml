--TEST--
Extension is loaded.
--SKIPIF--
<?php
require 'test-functions.php';
--FILE--
<?php
echo 'SFML extension version: ', phpversion('sfml'), PHP_EOL;

$ext = new ReflectionExtension('sfml');

$numFunctions = count($ext->getFunctions());
if($numFunctions)
	echo "$numFunctions functions defined", PHP_EOL;
else
	echo 'no functions defined', PHP_EOL;

$numClasses = count($ext->getClasses());
if($numClasses)
	echo "$numClasses classes defined", PHP_EOL;
else
	echo 'no functions defined', PHP_EOL;

$numConstants = count($ext->getConstants());
if($numConstants)
	echo "$numConstants constants defined", PHP_EOL;
else
	echo 'no constants defined', PHP_EOL;
--EXPECTF--
SFML extension version: %s
%d functions defined
%d classes defined
%d constants defined
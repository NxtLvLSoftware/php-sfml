--TEST--
sleep function tests
--SKIPIF--
<?php
require 'test-functions.php';
--FILE--
<?php
//make sure the sleep function exists
var_dump(function_exists("\\sf\\sleep"));

//make sleeping stops execution
$start = microtime();
\sf\sleep(\sf\milliseconds(10));
var_dump($start === microtime());

//make sleeping is accurate
$start = microtime(true);
\sf\sleep(\sf\seconds(2));
var_dump(microtime(true) - $start);
--EXPECTF--
bool(true)
bool(false)
float(2.00%d)
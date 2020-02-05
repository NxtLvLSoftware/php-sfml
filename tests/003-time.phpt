--TEST--
time class tests
--SKIPIF--
<?php
require 'test-functions.php';
--FILE--
<?php
//default time should be null/zero
var_dump($time = new \sf\Time());
var_dump($time->asSeconds());
var_dump($time->asMilliseconds());
var_dump($time->asMicroseconds());

//zero time should be null/zero
var_dump($time = \sf\Time::zero());
var_dump($time->asSeconds());
var_dump($time->asMilliseconds());
var_dump($time->asMicroseconds());

//constructing time from seconds
var_dump($time = \sf\seconds(1.5));
var_dump($time->asSeconds());
var_dump($time->asMilliseconds());
var_dump($time->asMicroseconds());

//constructing time from milliseconds
var_dump($time = \sf\milliseconds(1500));
var_dump($time->asSeconds());
var_dump($time->asMilliseconds());
var_dump($time->asMicroseconds());

//constructing time from microseconds
var_dump($time = \sf\microseconds(1500000));
var_dump($time->asSeconds());
var_dump($time->asMilliseconds());
var_dump($time->asMicroseconds());

//cloning a time object keeps its internal value
var_dump($time = \sf\seconds(2));
var_dump($time->asSeconds());
var_dump($time->asMilliseconds());
var_dump($time->asMicroseconds());
//var_dump($cloned = clone $time);
//var_dump($cloned->asSeconds());
//var_dump($cloned->asMilliseconds());
//var_dump($cloned->asMicroseconds());

--EXPECTF--
object(sf\Time)#%d (0) {
}
float(0)
int(0)
int(0)
object(sf\Time)#%d (0) {
}
float(0)
int(0)
int(0)
object(sf\Time)#%d (0) {
}
float(1.5)
int(1500)
int(1500000)
object(sf\Time)#%d (0) {
}
float(1.5)
int(1500)
int(1500000)
object(sf\Time)#%d (0) {
}
float(1.5)
int(1500)
int(1500000)
object(sf\Time)#%d (0) {
}
float(2)
int(2000)
int(2000000)

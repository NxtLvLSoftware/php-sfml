--TEST--
clock class tests
--SKIPIF--
<?php
require 'test-functions.php';
--FILE--
<?php
//make sure the class can be constructed
var_dump(new \sf\Clock);

//make sure the elapsed time is 0 when constructed
var_dump((new \sf\Clock)->getElapsedTime()->asMilliseconds());

//make sure the elapsed time is correct after sleeping
$clock = new \sf\Clock;
sleep(1);
var_dump($clock->getElapsedTime()->asMilliseconds());

//make sure the elapsed time is correct after sleeping and the clock is restarted
$clock = new \sf\Clock;
sleep(1);
var_dump($clock->restart()->asMilliseconds());
sleep(2);
var_dump($clock->restart()->asMilliseconds());
--EXPECTF--
object(sf\Clock)#%d (0) {
}
int(0)
int(100%d)
int(100%d)
int(200%d)
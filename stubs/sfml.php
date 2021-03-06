<?php

namespace sf {
function sleep(\sf\Time $duration) : void{}

function seconds(float $seconds) : \sf\Time{}

function milliseconds(int $seconds) : \sf\Time{}

function microseconds(int $seconds) : \sf\Time{}
}

namespace sf {
class Clock{

	public function __construct(){}

	public function getElapsedTime() : \sf\Time{}

	public function restart() : \sf\Time{}
}
}

namespace sf {
interface InputStream{

	public function read(?string &$data, int $size) : int;

	public function seek(int $position) : int;

	public function tell() : int;

	public function getSize() : int;
}
}

namespace sf {
class Time{

	public function __construct(){}

	public function asSeconds() : float{}

	public function asMilliseconds() : int{}

	public function asMicroseconds() : int{}

	public static function zero() : \sf\Time{}
}
}

const SFML_VERSION_MAJOR = 2;

const SFML_VERSION_MINOR = 5;

const SFML_VERSION_PATCH = 1;
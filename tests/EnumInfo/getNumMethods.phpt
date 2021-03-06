--TEST--
G\Introspection\EnumInfo->getNumMethods();
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
?>
--FILE--
<?php
use G\Introspection\Repository as Gir;

$repo = Gir::getDefault();

// load the repo - we'll do GLib since it SHOULD be around
$repo->require('GLib');

$baseinfo = $repo->findByName('GLib', 'AsciiType');
var_dump($baseinfo->getNumMethods());

// too many args
try {
     $baseinfo->getNumMethods(1);
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
= DONE =
--EXPECT--
int(0)
G\Introspection\EnumInfo::getNumMethods() expects exactly 0 parameters, 1 given
= DONE =
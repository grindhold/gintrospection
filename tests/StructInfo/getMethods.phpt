--TEST--
G\Introspection\StructInfo->getMethods();
--SKIPIF--
<?php
if(!extension_loaded('gi')) die('skip - GI extension not available');
?>
--FILE--
<?php
use G\Introspection\Repository as Gir;
use G\Introspection\FunctionInfo;

$repo = Gir::getDefault();

// load the repo - we'll do GLib since it SHOULD be around
$repo->require('GLib');

// has more then one count
$baseinfo = $repo->findByName('GLib', 'Timer');

$list = $baseinfo->getMethods();
$total = $baseinfo->getNumMethods();

var_dump(count($list) == $total);

$correct = 0;
foreach($list as $info) {
     if($info instanceof FunctionInfo) {
          $correct++;
     } else {
          var_dump($info);
     }
}

var_dump($correct == $total);

// too many args
try {
     $baseinfo->getMethods(1);
} catch (InvalidArgumentException $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
= DONE =
--EXPECT--
bool(true)
bool(true)
G\Introspection\StructInfo::getMethods() expects exactly 0 parameters, 1 given
= DONE =
<?php

use function PHPSTORM_META\map;

$N = (int)fgets(STDIN);
$x = array_map('intval', explode(' ', fgets(STDIN)));

[$a, $b, $c] = [0, 0, $x[0]];
for ($i = 0; $i < $N; $i++) {
    $a += abs($x[$i]);
    $b += $x[$i] ** 2;
    $c = max($c, abs($x[$i]));
}
print $a . "\n" . sqrt($b) . "\n" . $c;

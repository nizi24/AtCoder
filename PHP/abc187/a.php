<?php
fscanf(STDIN, '%s %s', $A, $B);
[$a, $b] = [0, 0];
for ($i = 0; $i < 3; $i++) {
    $a += intval($A[$i]);
    $b += intval($B[$i]);
}

print max($a, $b);
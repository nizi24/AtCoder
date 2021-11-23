<?php
fscanf(STDIN, '%d %d %d', $A, $B, $W);
$W *= 1000;

$max = 0;
$min = 10 ** 6 + 1;
for ($i = 1; $i <= 10 ** 6; $i++) {
    $weight = $W / $i;
    if ($A <= $weight && $weight <= $B) {
        $min = min($min, $i);
        $max = max($max, $i);
    }
}

if ($max == 0) print 'UNSATISFIABLE';
else print $min . ' ' . $max;
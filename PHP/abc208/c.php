<?php
fscanf(STDIN, "%d %d", $N, $K);
$a = explode(' ', rtrim(fgets(STDIN)));

asort($a);
$c = intdiv($K, $N);
$amari = $K % $N;
foreach ($a as $key => $value) {
    if ($amari > 0) $ans[$value] = $c + 1;
    else $ans[$value] = $c;
    $amari--;
}

ksort($a);
foreach ($a as $v) {
    echo $ans[$v];
    echo ' ';
}
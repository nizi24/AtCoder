<?php
fscanf(STDIN, '%d %d %d', $N, $M, $T);
[$A, $B] = [[], []];
for ($i = 0; $i < $M; $i++) fscanf(STDIN, '%d %d', $A[], $B[]);

$max = $N;
$prev = 0;
$ans = 'Yes';
for ($i = 0; $i < $M; $i++) {
    $N -= $A[$i] - $prev;
    if ($N <= 0) {
        $ans = 'No';
        break;
    }
    $N = min($max, $N + $B[$i] - $A[$i]);
    $prev = $B[$i];
}
if ($N - ($T - $prev) <= 0) $ans = 'No';

print $ans;
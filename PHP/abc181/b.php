<?php
$N = (int)fgets(STDIN);
[$A, $B] = [[], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $A[], $B[]);

$ans = 0;
for ($i = 0; $i < $N; $i++) {
    $ans += $B[$i] * ($B[$i] + 1) / 2;
    $ans -= $A[$i] * ($A[$i] - 1) / 2;
}
print $ans;
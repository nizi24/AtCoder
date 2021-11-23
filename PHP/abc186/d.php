<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

rsort($A);
$sum = 0;
for ($i = 0; $i < $N; $i++) $sum += $A[$i];

$ans = 0;
for ($i = 0; $i < $N-1; $i++) {
    $sum -= $A[$i];
    $ans += $A[$i] * ($N-$i-1) - $sum;
}
print $ans;
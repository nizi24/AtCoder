<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$ans = 0;
$sum = 0;
for ($i = 0; $i < $N; $i++) {
    $ans += $A[$i] ** 2 * ($N-1);
    $sum += $A[$i];
}

for ($i = 0; $i < $N; $i++) {
    $sum -= $A[$i];
    $ans -= 2 * $A[$i] * $sum;
}
print $ans;
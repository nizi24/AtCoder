<?php
$MOD = 1000000007;

$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$sum = 0;
for ($i = 0; $i < $N; $i++) {
    $sum += $A[$i];
    $sum %= $MOD;
}

$ans = 0;
for ($i = 0; $i < $N; $i++) {
    $sum -= $A[$i];
    $sum += $MOD;
    $sum %= $MOD;

    $ans += $A[$i] * $sum;
    $ans %= $MOD;
}
print $ans;
<?php
$P = (int)fgets(STDIN);
$fac[] = 1;
for ($i = 2; $i <= 10; $i++) {
    $fac[] = $fac[$i-2] * $i;
}

$ans = 0;
for ($i = 9; $i >= 0; $i--) {
    if (!$P) break;

    $ans += intdiv($P, $fac[$i]);
    $P %= $fac[$i];
}

echo $ans;
<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$modA = array_fill(0, 200, 0);
for ($i = 0; $i < $N; $i++) {
    $modA[$A[$i] % 200]++;
}

$ans = 0;
for ($i = 0; $i < 200; $i++) {
    $ans += $modA[$i] * ($modA[$i] - 1) / 2;
}

print $ans;
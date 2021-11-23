<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$ans = 0;
for ($i = 0; $i < $N; $i++) {
    $min = (1 << 20);
    for ($j = $i; $j < $N; $j++) {
        $min = min($min, $A[$j]);
        $ans = max($min * ($j - $i + 1), $ans);
    }
}

print $ans;
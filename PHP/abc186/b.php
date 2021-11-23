<?php
fscanf(STDIN, '%d %d', $H, $W);
$A = [];
for ($i = 0; $i < $H; $i++) {
    $A[] = array_map('intval', explode(' ', fgets(STDIN)));
}

$min = (1 << 20);
for ($i = 0; $i < $H; $i++) {
    for ($j = 0; $j < $W; $j++) {
        $min = min($min, $A[$i][$j]);
    }
}

$ans = 0;
for ($i = 0; $i < $H; $i++) {
    for ($j = 0; $j < $W; $j++) {
        $ans += $A[$i][$j] - $min;
    }
}
print $ans;
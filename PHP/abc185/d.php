<?php
fscanf(STDIN, '%d %d', $N, $M);
$A = $M == 0 ? [] : array_map('intval', explode(' ', rtrim(fgets(STDIN))));
$A[] = 0;
$A[] = $N + 1;
sort($A);

$blanks = [];
for ($i = 0; $i < $M+1; $i++) {
    $blank = $A[$i + 1] - $A[$i] - 1;
    if ($blank > 0) $blanks[] = $blank;
}

$blanks_size = sizeof($blanks);
;if ($blanks_size > 0) {
    $ans = 0;
    $min = $blanks[0];
    for ($i = 0; $i < $blanks_size; $i++) $min = min($min, $blanks[$i]);
    for ($i = 0; $i < $blanks_size; $i++) $ans += ceil($blanks[$i] / $min);
    print $ans;
} else print 0;
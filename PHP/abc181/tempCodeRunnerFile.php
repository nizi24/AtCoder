<?php
$S = rtrim(fgets(STDIN));

$num = array_fill(0, 10, 0);
for ($i = 0; $i < strlen($S); $i++) $num[intval($S[$i])]++;

$ans = 'No';
for ($i = 1; $i <= 9; $i++) {
    if ($num[$i] == 0) continue;
    $num[$i]--;
    for ($j = 1; $j <= 9; $j++) {
        if ($num[$j] == 0) continue;
        $num[$j]--;
        for ($k = 1; $k <= 9; $k++) {
            $cur = $i * 100 + $j * 10 + $k;
            if ($cur % 8 == 0 && $num[$k] > 0) $ans = 'Yes';
        }
        $num[$j]++;
    }
    $num[$i]++;
}
print $ans;
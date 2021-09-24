<?php
error_reporting(E_ALL & ~E_NOTICE);

fscanf(STDIN, "%d %d", $N, $K);
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, "%d %d", $key, $value);
    $A[$key] += $value;
}

ksort($A);
$flag = 0;
$pre = 0;
foreach ($A as $key => $value) {
    $K -= $key - $pre;
    if ($K >= 0) {
        $K += $value;
        $pre = $key;
    } else {
        echo $key + $K;
        $flag = 1;
        break;
    }
}
if (!$flag) {
    echo $pre + $K;
}
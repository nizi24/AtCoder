<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$max = 0;
$ans = 0;
for ($i = 2; $i <= 1000; $i++) {
    $cnt = 0;
    for ($j = 0; $j < $N; $j++) {
        if ($A[$j] % $i == 0) $cnt++;
    }
    if ($max < $cnt) {
        $max = $cnt;
        $ans = $i;
    }
}
print $ans;
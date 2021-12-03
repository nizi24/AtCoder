<?php
$N = (int)fgets(STDIN);
$L = array_map('intval', explode(' ', fgets(STDIN)));

$ans = 0;
for ($i = 0; $i < $N; $i++) {
    for ($j = $i + 1; $j < $N; $j++) {
        for ($k = $j + 1; $k < $N; $k++) {
            if ($L[$i] + $L[$j] > $L[$k] &&
                $L[$i] + $L[$k] > $L[$j] &&
                $L[$j] + $L[$k] > $L[$i] &&
                $L[$i] != $L[$j] && $L[$j] != $L[$k] &&
                $L[$i] != $L[$k]) {
                    $ans++;
                }
        }
    }
}
print $ans;
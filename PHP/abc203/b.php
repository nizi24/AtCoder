<?php
fscanf(STDIN, "%d %d", $N, $K);
$ans = 0;
for ($i = 0; $i < $N; $i++) {
    for ($j = 0; $j < $K; $j++) {
        $ans += 100 * ($i + 1);
        $ans += ($j + 1);
    }
}
echo $ans;
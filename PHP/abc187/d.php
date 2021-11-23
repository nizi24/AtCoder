<?php
$N = (int)fgets(STDIN);
[$A, $B] = [[], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $A[], $B[]);

$m = array_fill(0, $N, []);
$aoki_sum = 0;
for ($i = 0; $i < $N; $i++) {
    $m[$i] = [$A[$i] * 2 + $B[$i], $i];
    $aoki_sum += $A[$i];
}

rsort($m);
$takahashi_sum = 0;
for ($i = 0; $i < $N; $i++) {
    $takahashi_sum += $A[$m[$i][1]] + $B[$m[$i][1]];
    $aoki_sum -= $A[$m[$i][1]];
    if ($takahashi_sum > $aoki_sum) {
        print $i + 1;
        break;
    }
}
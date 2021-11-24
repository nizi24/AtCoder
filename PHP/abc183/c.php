<?php
fscanf(STDIN, '%d %d', $N, $K);
$T = [];
for ($i = 0; $i < $N; $i++) $T[] = array_map('intval', explode(' ', fgets(STDIN)));

$ans = 0;
$seen = array_fill(0, $N, false);
dfs(0, 0, $N, $K, 1, $T, $ans, $seen);
print $ans;

function dfs($n, $t, $N, $K, $cnt, &$T, &$ans, &$seen) {
    $seen[$n] = true;
    if ($cnt == $N && $t + $T[$n][0] == $K) $ans++;

    for ($i = 0; $i < $N; $i++) {
        if (!$seen[$i]) {
            dfs($i, $t + $T[$n][$i], $N, $K, $cnt+1, $T, $ans, $seen);
        }
    }

    $seen[$n] = false;
}
<?php
$N = (int)fgets(STDIN);
fscanf(STDIN, "%d %d", $X, $Y);
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, "%d %d", $A[], $B[]);
}

// dpテーブル
$dp = array_fill(0, $N+1, array_fill(0, $X+1, array_fill(0, $Y+1, $N+1)));
$dp[0][0][0] = 0;

for ($i = 0; $i < $N; $i++) {
    for ($j = 0; $j <= $X; $j++) {
        for ($k = 0; $k <= $Y; $k++) {
            // 購入する場合
            $next = &$dp[$i + 1][min($X, $j + $A[$i])][min($Y, $k + $B[$i])];
            $next = min($next, $dp[$i][$j][$k] + 1);

            // 購入しない場合
            $next = &$dp[$i + 1][$j][$k];
            $next = min($next, $dp[$i][$j][$k]);
        }
    }
}

if ($dp[$N][$X][$Y] == $N+1) echo -1;
else echo $dp[$N][$X][$Y];
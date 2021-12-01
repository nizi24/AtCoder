<?php
$S = (int)fgets(STDIN);

$dp = array_fill(0, $S+1, 0);
$dp[$S] = 1;
for ($i = $S; $i >= 0; $i--) {
    for ($j = 3; $j <= $i; $j++) {
        $dp[$i - $j] += $dp[$i];
        $dp[$i - $j] %= 1000000007;
    }
}
print $dp[0] % 1000000007;
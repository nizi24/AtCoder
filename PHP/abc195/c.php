<?php
$N = (int)fgets(STDIN);

$ans = 0;
for ($i = 3; $i < 16; $i += 3) {
    $under = 10 ** $i - 1;
    if ($under >= $N) break;
    $ans += $N - $under;
}
echo $ans;
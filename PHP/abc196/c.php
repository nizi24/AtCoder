<?php
$N = (int)fgets(STDIN);

$ans = 0;
for ($i = 1; $i < 1000000; $i++) {
    $cur = 10 ** strlen($i) * $i + $i;
    if ($N < $cur) break;
    $ans++;
}
print $ans;
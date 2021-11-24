<?php
$N = rtrim(fgets(STDIN));


$n = strlen($N);
$ans = $n;
for ($i = 0; $i < (1 << $n); $i++) {
    $tmp = "";
    for ($j = 0; $j < $n; $j++) {
        if ($i & (1 << $j)) $tmp .= $N[$j];
    }

    $cur = 0;
    $k = strlen($tmp);
    for ($j = 0; $j < $k; $j++) {
        $cur += 10 ** ($k - $j - 1) * intval($tmp[$j]);
    }

    if ($cur % 3 == 0) $ans = min($ans, $n - $k);
}
print $ans == $n ? -1 : $ans;
<?php
$N = (int)fgets(STDIN);

$ans = 0;
for ($i = 1; $i <= $N; $i++) {
    $str = strval($i);
    for ($j = 0; $j < strlen($str); $j++) {
        if ($str[$j] == '7') continue 2;
    }

    $cur = $i;
    for ($j = 6; $j >= 0; $j--) {
        if (intval($cur / (8 ** $j)) == 7) {
            continue 2;
        } else {
            $cur %= 8 ** $j;
        }
    }
    $ans++;
}
print $ans;
<?php
$L = (int)fgets(STDIN);
$L--;

$ans = 1;
$used = array_fill(0, 10, false);
for ($i = 0; $i < 11; $i++) {
    $ans *= $L - $i;
    for ($j = 2; $j <= 11; $j++) {
        if ($ans % $j == 0 && !$used[$j-2]) {
            $used[$j-2] = true;
            $ans /= $j;
        }
    }
}
print $ans;
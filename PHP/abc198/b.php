<?php
$N = rtrim(fgets(STDIN));

$ans = false;
for ($i = 0; $i < 10; $i++) {
    $size = strlen($N);
    $flag = true;
    for ($j = 0; $j < $size/2; $j++) {
        if ($N[$j] != $N[$size - $j - 1]) {
            $flag = false;
            break;
        }
    }

    if ($flag) {
        $ans = true;
        break;
    }

    $N = '0' . $N;
}

if ($ans) print 'Yes';
else print 'No';
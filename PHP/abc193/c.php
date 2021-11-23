<?php
$N = (int)fgets(STDIN);

$seen = array_fill(0, ceil(sqrt($N))+1, false);
$ans = $N;
for ($i = 2; $i * $i <= $N; $i++) {
    if (!$seen[$i]) {
        for ($j = 2; $i ** $j <= $N; $j++) {
            $ans--;
            $seen[$i ** $j] = true;
        }
    }
}

print $ans;
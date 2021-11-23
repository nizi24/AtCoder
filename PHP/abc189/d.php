<?php
$N = (int)fgets(STDIN);
$S = [];
for ($i = 0; $i < $N; $i++) {
    $S[] = rtrim(fgets(STDIN));
}

$ans = 1;
for ($i = 0; $i < $N; $i++) {
    if ($S[$i] == 'OR') {
        $ans += 2 ** ($i + 1);
    }
}

print $ans;
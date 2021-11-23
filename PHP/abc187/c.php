<?php
$N = (int)fgets(STDIN);
$S = [];
for ($i = 0; $i < $N; $i++) $S[] = fgets(STDIN);

$s = [];
for ($i = 0; $i < $N; $i++) {
    $s[$S[$i]] = 1;
}

$ans = 'satisfiable';
for ($i = 0; $i < $N; $i++) {
    if ($S[$i][0] == '!') {
        if (isset($s[substr($S[$i], 1)])) $ans = substr($S[$i], 1);
    } else {
        if (isset($s['!' . $S[$i]])) $ans = $S[$i];
    }
}
print $ans;
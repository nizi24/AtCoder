<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));
$B = array_map('intval', explode(' ', fgets(STDIN)));
$C = array_map('intval', explode(' ', fgets(STDIN)));

for ($i = 0; $i < $N; $i++) {
    $b[$B[$C[$i]-1]]++;
}

$ans = 0;
for ($i = 0; $i < $N; $i++) {
    $ans += $b[$A[$i]];
}

echo $ans;
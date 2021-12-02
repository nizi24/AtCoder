<?php
$S = rtrim(fgets(STDIN));
$T = rtrim(fgets(STDIN));

$ans = strlen($T);
for ($i = 0; $i < strlen($S)-strlen($T)+1; $i++) {
    $cnt = 0;
    for ($j = 0; $j < strlen($T); $j++) {
        if ($S[$i+$j] != $T[$j]) $cnt++;
    }
    $ans = min($ans, $cnt);
}
print $ans;
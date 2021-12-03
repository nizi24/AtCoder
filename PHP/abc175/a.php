<?php
$S = rtrim(fgets(STDIN));

$pre = 0;
$ans = 0;
for ($i = 0; $i < 3; $i++) {
    if (!$pre && $S[$i] == 'R') {
        $pre = 1;
        $ans = 1;
    } else if ($pre && $S[$i] == 'R') $ans++;
    else $pre = 0;
}
print $ans;
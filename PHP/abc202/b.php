<?php
$S = rtrim(fgets(STDIN));
$ans = [];
for ($i = 0; $i < strlen($S); $i++) {
    if ($S[$i] === '6') $ans[] = '9';
    elseif ($S[$i] === '9') $ans[] = '6';
    else $ans[] = $S[$i];
}
$ans = array_reverse($ans);
echo implode('', $ans);
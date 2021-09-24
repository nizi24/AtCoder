<?php
$strs = [];
for ($i = 0; $i < 3; $i++) {
    $strs[] = fgets(STDIN);
}
$nums = fgets(STDIN);

$ans = '';
for ($i = 0; $i < strlen($nums)-1; $i++) {
    $ans .= $strs[$nums[$i]-1];
}
$ans = str_replace(PHP_EOL, '', $ans);
echo $ans;

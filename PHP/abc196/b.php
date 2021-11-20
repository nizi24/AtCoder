<?php
$X = fgets(STDIN);
$ans = "";
for ($i = 0; $i < strlen($X); $i++) {
    if ($X[$i] == ".") break;
    
    $ans .= $X[$i];
}
print $ans;
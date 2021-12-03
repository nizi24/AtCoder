<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$max = 0;
$ans = 0;
for ($i = 0; $i < $N; $i++) {
    if ($max < $A[$i]) $max = $A[$i];
    else $ans += $max - $A[$i];
}
print $ans;
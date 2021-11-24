<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$rui = [$A[0]];
for ($i = 1; $i < $N; $i++) $rui[] = $rui[$i-1] + $A[$i];

$cur = 0;
$rui_max = 0;
$ans = 0;
for ($i = 0; $i < $N; $i++) {
    $ans = max($ans, $cur + $rui_max);
    $cur += $rui[$i];
    $rui_max = max($rui_max, $rui[$i]);
}
$ans = max($ans, $cur);
print $ans;
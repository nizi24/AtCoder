<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));
$B = array_map('intval', explode(' ', fgets(STDIN)));
sort($A);
sort($B);

echo max(0, $B[0] - $A[$N-1] + 1);
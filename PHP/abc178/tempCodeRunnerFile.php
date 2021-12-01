<?php
$N = (int)fgets(STDIN);

$A = 10 ** $N;
$B = 8 ** $N;
print ($A - $B + 1000000007) % 1000000007;
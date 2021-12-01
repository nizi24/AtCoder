<?php
fscanf(STDIN, '%d %d %d %d', $a, $b, $c, $d);
$ans = max($a * $c, $a * $d, $b * $c, $b * $d);
print $ans;
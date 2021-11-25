<?php
fscanf(STDIN, '%d %d %d %d', $X, $Y, $A, $B);

$ans = 0;
while ($Y > $X) {
    if ($X * $A < $X + $B) {
        $X *= $A;
        $ans++;
    } else {
        $ans += intval(($Y - $X - 1) / $B);
        break;
    }
}
print $ans . "\n";
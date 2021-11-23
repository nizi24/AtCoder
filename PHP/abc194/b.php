<?php
$N = (int)fgets(STDIN);
[$A, $B] = [[], []];
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, "%d %d", $A[], $B[]);
}

$ans = (1 << 20);
for ($i = 0; $i < $N; $i++) {
    for ($j = 0; $j < $N; $j++) {
        if ($i == $j) $ans = min($ans, $A[$i] + $B[$j]);
        else $ans = min($ans, max($A[$i], $B[$j]));
    }
}
print $ans;

<?php
$N = (int)fgets(STDIN);
[$A, $P, $X] = [[], [], []];
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, '%d %d %d', $A[], $P[], $X[]);
}

$min = (1 << 30);
for ($i = 0; $i < $N; $i++) {
    if ($X[$i] - $A[$i] > 0) {
        $min = min($min, $P[$i]);
    }
}
print $min == (1 << 30) ? -1 : $min;
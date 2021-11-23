<?php
fscanf(STDIN, '%d %d', $N, $X);
[$V, $P] = [[], []];
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, '%d %d', $V[], $P[]);
}

$X *= 100;
$al = 0;
for ($i = 0; $i < $N; $i++) {
    $al += $V[$i] * $P[$i];
    if ($al > $X) {
        echo $i + 1;
        break;
    }
}

if ($al <= $X) echo -1;
<?php
fscanf(STDIN, '%d %d %d', $N, $S, $D);
[$X, $Y] = [[], []];
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, '%d %d', $X[], $Y[]);
}

$ans = false;
for ($i = 0; $i < $N; $i++) {
    if ($X[$i] < $S && $Y[$i] > $D) $ans = true;
}
print $ans ? 'Yes' : 'No';
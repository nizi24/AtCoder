<?php
$N = (int)fgets(STDIN);
[$x, $y] = [[], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $x[], $y[]);

[$xy1, $xy2] = [[], []];
for ($i = 0; $i < $N; $i++) {
    $xy1[] = $x[$i] + $y[$i];
    $xy2[] = $x[$i] - $y[$i];
}

sort($xy1);
sort($xy2);

print max($xy1[$N-1] - $xy1[0], $xy2[$N-1] - $xy2[0]);
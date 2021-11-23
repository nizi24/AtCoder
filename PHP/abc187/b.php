<?php
$N = (int)fgets(STDIN);
[$x, $y] = [[], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $x[], $y[]);

$ans = 0;
for ($i = 0; $i < $N; $i++) {
    for ($j = $i + 1; $j < $N; $j++) {
        if ($x[$i] - $x[$j] == 0) {
            $ans++;
            continue;
        }

        $t = ($y[$i] - $y[$j]) / ($x[$i] - $x[$j]);
        if (abs($t) <= 1) $ans++;
    }
}
print $ans;
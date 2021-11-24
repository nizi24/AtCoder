<?php
$N = (int)fgets(STDIN);
[$x, $y] = [[], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $x[], $y[]);

$ans = 'No';
for ($i = 0; $i < $N; $i++) {
    for ($j = $i + 1; $j < $N; $j++) {
        $flag = $x[$i] == $x[$j];
        $t = 0;
        if (!$flag) $t = ($y[$i] - $y[$j]) / ($x[$i] - $x[$j]);
        $p = $t * (-$x[$i]) + $y[$i];
        for ($k = $j + 1; $k < $N; $k++) {
            if ($flag) {
                if ($x[$i] == $x[$k]) {
                    $ans = 'Yes';
                    break 3;
                }
            } else if ($y[$k] == $t * $x[$k] + $p) {
                $ans = 'Yes';
                break 3;
            }
        }
    }
}
print $ans;
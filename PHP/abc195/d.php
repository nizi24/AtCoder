<?php

use function PHPSTORM_META\map;

fscanf(STDIN, '%d %d %d', $N, $M, $Q);
[$W, $V] = [[], []];
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, '%d %d', $W[], $V[]);
}
$X = array_map('intval', explode(' ', fgets(STDIN)));
[$L, $R] = [[], []];
for ($i = 0; $i < $Q; $i++) {
    fscanf(STDIN, '%d %d', $L[], $R[]);
}

for ($i = 0; $i < $Q; $i++) {
    $boxes = [];
    for ($j = 0; $j < $M; $j++) {
        if ($L[$i]-1 > $j || $R[$i]-1 < $j) {
            $boxes[] = $X[$j];
        } 
    }
    sort($boxes);

    $ans = 0;
    $used = array_fill(0, $N, false);
    foreach ($boxes as $box) {
        $max = 0;
        $max_index = -1;
        for ($k = 0; $k < $N; $k++) {
            if ($box >= $W[$k] && $used[$k] == 0) {
                if ($max < $V[$k]) {
                    $max = $V[$k];
                    $max_index = $k;
                }
            }
        }
        if ($max_index != -1) $used[$max_index] = true;
        $ans += $max;
    }

    print $ans . "\n";
}
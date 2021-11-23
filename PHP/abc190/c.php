<?php
fscanf(STDIN, '%d %d', $N, $M);
[$A, $B] = [[], []];
for ($i = 0; $i < $M; $i++) {
    fscanf(STDIN, '%d %d', $A[], $B[]);
}
$K = (int)fgets(STDIN);
[$C, $D] = [[], []];
for ($i = 0; $i < $K; $i++) {
    fscanf(STDIN, '%d %d', $C[], $D[]);
}

$ans = 0;
for ($i = 0; $i < (1 << $K); $i++) {
    $set = array_fill(0, $N, false);
    for ($j = 0; $j < $K; $j++) {
        if ($i & (1 << $j)) {
            $set[$C[$j]-1] = true;
        } else {
            $set[$D[$j]-1] = true;
        }
    }

    $cnt = 0;
    for ($j = 0; $j < $M; $j++) {
        if ($set[$A[$j]-1] && $set[$B[$j]-1]) $cnt++;
    }

    $ans = max($ans, $cnt);
}

print $ans;
<?php

use function PHPSTORM_META\map;

fscanf(STDIN, '%d %d', $N, $M);
$A = array_map('intval', explode(' ', fgets(STDIN)));
[$X, $Y] = [[], []];
for ($i = 0; $i < $M; $i++) {
    fscanf(STDIN, '%d %d', $X[], $Y[]);
}

$G = array_fill(0, $N, []);
$parent_cnt = array_fill(0, $N, 0);
for ($i = 0; $i < $M; $i++) {
    $G[$X[$i]-1][] = $Y[$i]-1;
    $parent_cnt[$Y[$i]-1]++;
}

$ans = -(1 << 30);
$min = array_fill(0, $N, (1 << 31));
$seen = array_fill(0, $N, false);
$q = new SplQueue();

for ($i = 0; $i < $N; $i++) {
    if (!$seen[$i]) {
        $seen[$i] = true;
        $q->enqueue($i);

        while (!$q->isEmpty()) {
            $p = $q->dequeue();
            $ans = max($ans, $A[$p]-$min[$p]);

            foreach ($G[$p] as $next) {
                $parent_cnt[$next]--;
                $min[$next] = min($min[$next], $min[$p], $A[$p]);
                
                if (!$parent_cnt[$next] && !$seen[$next]) {
                    $seen[$next] = true;
                    $q->enqueue($next);
                }
            }
        }
    }
}

print $ans;

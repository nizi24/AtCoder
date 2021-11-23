<?php
fscanf(STDIN, "%d %d", $N, $M);
$A = array_map("intval", explode(" ", fgets(STDIN)));

$mex_vector = array_fill(0, $N, 0);
$min = $N;
for ($i = 0; $i < $M; $i++) {
    $mex_vector[$A[$i]]++;
}

for ($i = 0; $i < $N; $i++) {
    if ($mex_vector[$i] == 0) $min = min($min, $i);
}

for ($i = $M; $i < $N; $i++) {
    $mex_vector[$A[$i - $M]]--;
    $mex_vector[$A[$i]]++;

    if ($mex_vector[$A[$i - $M]] <= 0) $min = min($min, $A[$i - $M]);
}

print $min;
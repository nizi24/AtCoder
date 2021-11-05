<?php
fscanf(STDIN, "%d %d", $N, $K);

for ($i = 0; $i < $K; $i++) {
    if ($N % 200 == 0) $N /= 200;
    else {
        $N *= 1000;
        $N += 200;
    }
}

print $N;
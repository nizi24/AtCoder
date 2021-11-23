<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));

$cur = [];
for ($i = 0; $i < (1 << $N); $i++) {
    $cur[] = [$i+1, $A[$i]];
}

for ($i = 0; $i < $N-1; $i++) {
    $next = [];
    for ($j = 0; $j < (1 << ($N - $i)); $j += 2) {
        if ($cur[$j][1] > $cur[$j+1][1]) $next[] = $cur[$j];
        else $next[] = $cur[$j+1];
    }
    $cur = $next;
}
print $cur[0][1] > $cur[1][1] ? $cur[1][0] : $cur[0][0];
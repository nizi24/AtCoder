<?php
fscanf(STDIN, '%d %d', $N, $c);
[$A, $B, $C] = [[], [], []];
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, '%d %d %d', $A[], $B[], $C[]);
}

$events = [];
for ($i = 0; $i < $N; $i++) {
    $events[] = [$A[$i], $C[$i]];
    $events[] = [$B[$i]+1, -$C[$i]];
}
sort($events);

$prev = 0;
$cur = 0;
$ans = 0;
for ($i = 0; $i < $N * 2; $i++) {
    $now = $events[$i][0];
    $ans += min($cur, $c) * ($now - $prev);
    $prev = $events[$i][0];
    $cur += $events[$i][1];
}

print $ans;
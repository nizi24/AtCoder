<?php
fscanf(STDIN, '%d %d', $N, $W);
[$S, $T, $P] = [[], [], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d %d', $S[], $T[], $P[]);

$events = [];
for ($i = 0; $i < $N; $i++) {
    $events[] = [$S[$i], $P[$i]];
    $events[] = [$T[$i], -$P[$i]];
}
sort($events);

$cnt = 0;
$ans = 'Yes';
for ($i = 0; $i < 2 * $N; $i++) {
    if ($cnt > $W) $ans = 'No';
    $cnt += $events[$i][1];
}
print $ans;
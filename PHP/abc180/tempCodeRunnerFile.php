<?php
$N = (int)fgets(STDIN);

$ans = [];
for ($i = 1; $i * $i <= $N; $i++) {
    if ($N % $i == 0) {
        $ans[] = $i;
        if ($N/$i != $i) $ans[] = $N/$i;
    }
}
sort($ans);

for ($i = 0; $i < sizeof($ans); $i++) {
    print $ans[$i] . "\n";
}
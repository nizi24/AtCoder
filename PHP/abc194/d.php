<?php
$N = (int)fgets(STDIN);
$renketu_nodes = 1;
$ans = 0;
for ($i = 0; $i < $N-1; $i++) {
    $ans += 1 / ($renketu_nodes / $N);
    $renketu_nodes++;
}
print $ans;
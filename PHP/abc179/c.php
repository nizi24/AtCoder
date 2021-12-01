<?php
$N = (int)fgets(STDIN);

$ans = 0;
for ($i = 1; $i < $N; $i++) {
    $ans += intval(($N-1) / $i);
}
print $ans;
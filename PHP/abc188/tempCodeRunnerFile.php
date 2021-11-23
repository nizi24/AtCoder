<?php
$N = (int)fgets(STDIN);
$A = array_map('intval', explode(' ', fgets(STDIN)));
$B = array_map('intval', explode(' ', fgets(STDIN)));

$tmp = 0;
for ($i = 0; $i < $N; $i++) {
    $tmp += $A[$i] * $B{$i};
}
print $tmp == 0 ? 'Yes' : 'No';
<?php
$N = (int)fgets(STDIN);
$ans = [];
while ($N > 0) {
    if ($N % 2 == 0) {
        $N /= 2;
        $ans[] = 'B';
    } else {
        $N--;
        $ans[] = 'A';
    }
}
$ans = array_reverse($ans);
echo implode('', $ans);
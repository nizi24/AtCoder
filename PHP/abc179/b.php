<?php
$N = (int)fgets(STDIN);
[$D1, $D2] = [[], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $D1[], $D2[]);

$zorome = 0;
$ans = 'No';
for ($i = 0; $i < $N; $i++) {
    if ($D1[$i] == $D2[$i]) $zorome++;
    else $zorome = 0;
    if ($zorome >= 3) {
        $ans = 'Yes';
        break;
    }
}

print $ans;
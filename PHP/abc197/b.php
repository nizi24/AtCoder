<?php
fscanf(STDIN, "%d %d %d %d", $H, $W, $Y, $X);
$S = [];
for ($i = 0; $i < $H; $i++) {
    $S[] = rtrim(fgets(STDIN));
}

$ans = 1;
$X--; $Y--;

// 左
for ($i = $X-1; $i >= 0; $i--) {
    if ($S[$Y][$i] == '#') break;
    $ans++;
}
// 右
for ($i = $X+1; $i < $W; $i++) {
    if ($S[$Y][$i] == '#') break;
    $ans++;
}
// 上
for ($i = $Y-1; $i >= 0; $i--) {
    if ($S[$i][$X] == '#') break;
    $ans++;
}
// 下
for ($i = $Y+1; $i < $H; $i++) {
    if ($S[$i][$X] == '#') break;
    $ans++;
}

print $ans;
<?php
fscanf(STDIN, '%d %d', $H, $W);
fscanf(STDIN, '%d %d', $CH, $CW);
fscanf(STDIN, '%d %d', $DH, $DW);

$S = [];
for ($i = 0; $i < $H; $i++) $S[] = rtrim(fgets(STDIN));

$direction = [[0, 1], [1, 0], [0, -1], [-1, 0]];

$que = new Ds\Deque();
$dist = array_fill(0, $H, array_fill(0, $W, (1 << 30)));
$dist[$CH-1][$CW-1] = 0;
$que->push([$CH-1, $CW-1]);

while (!$que->isEmpty()) {
    $t = $que->pop();
    $y = $t[0];
    $x = $t[1];

    // 歩く
    for ($i = 0; $i < 4; $i++) {
        $ny = $y + $direction[$i][0];
        $nx = $x + $direction[$i][1];
        
        if (isValid($ny, $nx, $H, $W)) {
            $que->insert(0, [$ny, $nx]);
            $dist[$ny][$nx] = $dist[$y][$x];
        }
    }

    // ワープ
    for ($i = -2; $i <= 2; $i++) {
        for ($j = -2; $j <= 2; $j++) {
            $ny = $y + $i;
            $nx = $x + $j;
            if (isValid($ny, $nx, $H, $W)) {
                $que->push([$ny, $nx]);
                $dist[$ny][$nx] = $dist[$y][$x] + 1;
            }
        }
    }
}

print $dist[$DH-1][$DW-1] == (1 << 30) ? -1 : $dist[$DH-1][$DW-1];


function isValid($y, $x, $H, $W) {
    if ($y >= $H || $y < 0) return false;
    if ($x >= $W || $x < 0) return false;
    return true;
}
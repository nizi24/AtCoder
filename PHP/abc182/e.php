<?php
fscanf(STDIN, '%d %d %d %d', $H, $W, $N, $M);
[$A, $B, $C, $D] = [[], [], [], []];
for ($i = 0; $i < $N; $i++) fscanf(STDIN, '%d %d', $A[], $B[]);
for ($i = 0; $i < $M; $i++) fscanf(STDIN, '%d %d', $C[], $D[]);

$akari = array_fill(0, $H, array_fill(0, $W, '.'));
for ($i = 0; $i < $N; $i++) $akari[$A[$i]-1][$B[$i]-1] = 'A';
for ($i = 0; $i < $M; $i++) $akari[$C[$i]-1][$D[$i]-1] = '#';

// 上から下へ
for ($j = 0; $j < $W; $j++) {
    $hikari = false;
    for ($i = 0; $i < $H; $i++) {
        if ($akari[$i][$j] == '#') $hikari = false;
        else if ($akari[$i][$j] == 'A') $hikari = true;
        else if ($hikari) $akari[$i][$j] = 'H';
    }
}
// 下から上へ
for ($j = 0; $j < $W; $j++) {
    $hikari = false;
    for ($i = $H-1; $i >= 0; $i--) {
        if ($akari[$i][$j] == '#') $hikari = false;
        else if ($akari[$i][$j] == 'A') $hikari = true;
        else if ($hikari) $akari[$i][$j] = 'H';
    }
}

// 左から右へ
for ($i = 0; $i < $H; $i++) {
    $hikari = false;
    for ($j = 0; $j < $W; $j++) {
        if ($akari[$i][$j] == '#') $hikari = false;
        else if ($akari[$i][$j] == 'A') $hikari = true;
        else if ($hikari) $akari[$i][$j] = 'H';
    }
}

// 右から左へ
for ($i = 0; $i < $H; $i++) {
    $hikari = false;
    for ($j = $W-1; $j >= 0; $j--) {
        if ($akari[$i][$j] == '#') $hikari = false;
        else if ($akari[$i][$j] == 'A') $hikari = true;
        else if ($hikari) $akari[$i][$j] = 'H';
    }
}

// 集計
$ans = 0;
for ($i = 0; $i < $H; $i++) {
    for ($j = 0; $j < $W; $j++) {
        if ($akari[$i][$j] == 'A' || $akari[$i][$j] == 'H') $ans++;
    }
}

print $ans;
<?php
$N = (int)fgets(STDIN);
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, "%s %d", $key, $value);
    $M[$key] = $value;
}

asort($M);
$cnt = 0;
foreach ($M as $key => $value) {
    $cnt++;
    if ($cnt == $N-1) {
        echo $key;
        break;
    }
}
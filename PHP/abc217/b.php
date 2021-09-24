<?php
$a = ['ABC', 'ARC', 'AGC', 'AHC'];
for ($i = 0; $i < 3; $i++) {
    $b[] = rtrim(fgets(STDIN));
}
foreach ($a as $v) {
    if (!in_array($v, $b)) {
        echo $v;
        break;
    }
}
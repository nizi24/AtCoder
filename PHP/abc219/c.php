<?php
$X = rtrim(fgets(STDIN));
$a = 'a';
for ($i = 0; $i < 26; $i++) {
    $mp[$X[$i]] = $a;
    $a++;
}

$N = fgets(STDIN);
for ($i = 0; $i < $N; $i++) {
    $strs[] = rtrim(fgets(STDIN));

    $tmp = '';
    for ($j = 0; $j < strlen($strs[$i]); $j++) {
        $tmp .=  $mp[$strs[$i][$j]];
    }
    $tmp_strs[] = $tmp;
}

asort($tmp_strs);
foreach ($tmp_strs as $key => $value) {
    echo $strs[$key]."\n";
}
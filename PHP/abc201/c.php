<?php
$S = rtrim(fgets(STDIN));

for ($i = 0; $i < strlen($S); $i++) { 
    if ($S[$i] === 'o') $need[] = $i;
    else if ($S[$i] === '?') $Q[] = $i;
    else $bad[] = $i;
}

if (count($need) > 4) {
    echo 0;
} else {
    $ans = 0;
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            for ($k = 0; $k < 10; $k++) {
                for ($l = 0; $l < 10; $l++) {
                    $ary = [$i, $j, $k, $l];
                    $need_tmp = $need;
                    foreach ($ary as $v) {
                        $need_tmp = array_filter($need_tmp, function($var) use($v) {
                            return $var != $v;
                        });
                        if (in_array($v, $bad)) {
                            continue 2;
                        }
                    }
                    if (!count($need_tmp)) $ans++;
                }
            }
        }
    }

    echo $ans;
}
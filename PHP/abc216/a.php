<?php
$S = fgets(STDIN);
for ($i = 0; $i < strlen($S); $i++) {
    if ($S[$i] === '.') {
        if ($S[$i+1] <= 2) echo '-';
        else if ($S[$i+1] <= 6) {

        } else {
            echo '+';
        }
        break;
    } else {
        echo $S[$i];
    }
}
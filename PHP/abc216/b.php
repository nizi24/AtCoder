<?php
$N = (int)fgets(STDIN);
$flag = true;
for ($i = 0; $i < $N; $i++) {
    fscanf(STDIN, "%s %s", $key, $value);
    if ($S[$key] === $value) {
        echo 'Yes';
        $flag = false;
        break;
    }
    $S[$key] = $value; 
}
if ($flag) echo 'No';
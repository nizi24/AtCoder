<?php
$N = rtrim(fgets(STDIN));

$sum = 0;
for ($i = 0; $i < strlen($N); $i++) {
    $sum += intval($N[$i]);
}
print $sum % 9 == 0 ? 'Yes' : 'No';

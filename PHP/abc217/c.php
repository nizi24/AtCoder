<?php
$N = (int)fgets(STDIN);
$p = array_map('intval', explode(' ', fgets(STDIN)));
for ($i = 0; $i < $N; $i++) {
    $q[$p[$i]-1] = $i + 1;
}

for ($i=0; $i < $N; $i++) { 
    echo $q[$i];
    echo ' ';
}
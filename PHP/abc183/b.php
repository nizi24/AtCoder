<?php
fscanf(STDIN, '%d %d %d %d', $SX, $SY, $GX, $GY);
$t = -($SY + $GY) / ($GX - $SX);
$p = $SY - $SX * $t;
print - ($p / $t);
<?php
fscanf(STDIN, '%d %d', $M, $H);
if ($H % $M == 0) echo 'Yes';
else echo 'No';
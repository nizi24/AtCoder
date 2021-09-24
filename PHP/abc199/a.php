<?php
fscanf(STDIN, "%d %d %d", $A, $B, $C);
if ($A ** 2 + $B ** 2 < $C ** 2) echo 'Yes';
else echo 'No';
<?php
fscanf(STDIN, "%d %d", $A, $B);
if ($A <= $B && $A * 6 >= $B) echo 'Yes';
else echo 'No';
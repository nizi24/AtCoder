<?php
fscanf(STDIN, "%d %d %d", $A[], $A[], $A[]);
sort($A);
if ($A[2] - $A[1] == $A[1] - $A[0]) echo 'Yes';
else echo 'No';
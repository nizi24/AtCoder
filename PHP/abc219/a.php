<?php
fscanf(STDIN, "%d", $X);
if ($X >= 90) echo 'expert';
elseif ($X >= 70) echo 90 - $X;
elseif ($X >= 40) echo 70 - $X;
else echo 40 - $X;
<?php
fscanf(STDIN, '%d %d %d', $A, $B, $C);
if ($A > $B) echo 'Takahashi';
else if ($A < $B) echo 'Aoki';
else {
    if ($C == 0) echo 'Aoki';
    else echo 'Takahashi';
}
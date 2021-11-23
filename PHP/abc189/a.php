<?php
$C = fgets(STDIN);
print ($C[0] == $C[1] && $C[1] == $C[2]) ? 'Won' : 'Lost';
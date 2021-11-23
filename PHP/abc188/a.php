<?php
fscanf(STDIN, '%d %d', $X, $Y);
print abs($X - $Y) < 3 ? 'Yes' : 'No';
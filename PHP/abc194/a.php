<?php
fscanf(STDIN, "%d %d", $a, $b);
if ($a + $b >= 15 && $b >= 8) {
    print 1;
} else if ($a + $b >= 10 && $b >= 3) {
    print 2;
} else if ($a + $b >= 3) {
    print 3;
} else {
    print 4;
}
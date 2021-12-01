<?php
$S = rtrim(fgets(STDIN));
print $S . ($S[strlen($S)-1] == 's' ? 'es' : 's');
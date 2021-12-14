bool first_zero = 0;
    // REP (i, cnt) {
    //     mask -= pw(2, i);
    //     if (first_zero) {
    //         if ((1 << i) & L) {
    //             G[20-cnt-1].push_back({20-i, (L & mask)});
    //         }
    //     } else {
    //         if (!((1 << i) & L)) {
    //             first_zero = 1;
    //             G[20-cnt-1].push_back({20-i, (L & mask)});
    //         }
    //     }
    // }
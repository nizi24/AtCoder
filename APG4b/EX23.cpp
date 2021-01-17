#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int64_t, int> count;
    for (int i = 0; i < n; i++) {
        int nn;
        cin >> nn;
        count[nn] += 1;
    }
    int64_t max_cnt = 0;
    int64_t max = 0;
    for (auto pair : count) {
        if (max_cnt < pair.second) {
            max = pair.first;
            max_cnt = pair.second;
        }
    }
    printf("%ld %d\n", max, max_cnt);
}
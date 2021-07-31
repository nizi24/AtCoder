#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    REP (i, N) cin >> d[i];

    int holiday = 0;
    REP (i, 7) holiday += 1 - d[i];

    int cnt = 0, ans = 0;
    if (holiday >= 2) {
        cnt = 7;
        ans = 7;
    }

    for (int i = 7; i < N; i++) {
        holiday += 1 - d[i];
        holiday -= 1 - d[i - 7];

        if (holiday >= 2) {
            if (cnt >= 7) cnt++;
            else cnt = 7;
        } else cnt = 0;

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
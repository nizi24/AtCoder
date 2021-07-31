#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)


int main() {
    int d, n;
    cin >> d >> n;
    vector<int> a(n);
    REP (i, n) cin >> a[i];

    vector<vector<bool>> dp(n+1, vector<bool>(d*2+10, 0));
    vector<vector<int>> next(n+1, vector<int>(d*2+10, -1));

    dp[0][d] = 1;

    REP (i, n) {
        REP (j, d*2+1) {
            if (dp[i][j]) {
                if (j - a[i] >= 0) {
                    dp[i + 1][j - a[i]] = true;
                    next[i][j] = j - a[i];
                }

                if (j + a[i] < d*2+1) {
                    dp[i + 1][j + a[i]] = true;
                    next[i][j] = j + a[i];
                }
            }
        }
    }

    string ans = "";
    int cur = d;
    REP (i, n) {
        if (cur > next[i][cur]) ans.push_back('L');
        else ans.push_back('R');

        cur = next[i][cur];

        cout << cur << endl;
    }

    cout << ans << endl;

    return 0;
}
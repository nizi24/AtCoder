#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
        sum += p.at(i);
    }
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int sm = 0; sm <= sum; sm++) {
            if (dp[i][sm]) {
                dp[i+1][sm] = true;
                dp[i+1][sm+p[i]] = true;
            }
        }
    }
    int ans = 0;
    for (int sm = 0; sm <= sum; sm++) {
        if (dp[n][sm]) ans++;
    }
    cout << ans << endl;
}
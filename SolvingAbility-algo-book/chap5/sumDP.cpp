#include <bits/stdc++.h>
using namespace std;
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n+1000);
    REP(i, n) cin >> h[i];
    vector<int> dp(n+1000, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        chmax(dp[i], dp[i-1] + h[i-1]);
        chmax(dp[i], dp[i-1]);
    }
    cout << dp[n] << endl;
}
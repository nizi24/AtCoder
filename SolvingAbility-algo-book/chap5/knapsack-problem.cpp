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
    int N, W;
    cin >> N >> W;
    vector<int> value(N+10), weight(N+10);
    REP(i, N) cin >> value[i] >> weight[i];
    vector<vector<int> > dp(N+10, vector<int>(W+10, 0));
    for (int n = 0; n < N; n++) {
        for (int w = 0; w <= W; w++) {
            if (w - weight[n] >= 0) {
                chmax(dp[n+1][w], dp[n][w - weight[n]] + value[n]);
            }
            chmax(dp[n+1][w], dp[n][w]);
        }
    }
    cout << dp[N][W] << endl;
}
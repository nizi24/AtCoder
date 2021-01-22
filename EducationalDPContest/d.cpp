#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
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
    int N, K;
    cin >> N >> K;
    vector<vector<i64>> wv(N+10, vector<i64>(2, -1));
    REP(i, N) REP(j, 2) cin >> wv[i][j];
    vector<vector<i64>> dp(N+10, vector<i64>(K+10, 0));
    for (int i = 0; i < N; i++) {
        for (int w = 0; w <= K; w++) {
            if (w - wv[i][0] >= 0) {
                chmax(dp[i+1][w], dp[i][w - wv[i][0]] + wv[i][1]);
            }
            chmax(dp[i+1][w], dp[i][w]);
        }
    }
    cout << dp[N][K] << endl;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
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
template<class T>
inline T sum(T n){return n*(n+1)/2;}

long long K;
string N;
void solve() {
	int l = N.size();
	// DPテーブル
	vector<vector<vector<long long>>> dp(l+1, vector<vector<long long>>(2, vector<long long>(K+2, 0)));

	// 初期条件
	dp[0][0][0] = 1;

	// 遷移
	REP (i, l) {
		REP (smaller, 2) {
			for (int x = 0; x <= (smaller ? 9 : N[i] - '0'); x++) {
				REP (j, K+1) {
					if (x == 0) dp[i + 1][smaller || x < (N[i] - '0')][j] += dp[i][smaller][j];
					else dp[i + 1][smaller || x < (N[i] - '0')][j + 1] += dp[i][smaller][j];
				}
			}
		}
	}

	cout << dp[l][0][K] + dp[l][1][K] << endl;
}

int main(){
    std::cin >> N;
    scanf("%lld",&K);
	solve();
    return 0;
}

// void dfs(int n, long long cnt, long long cur) {
// 	if (cnt == K-1) {
// 		ans += cur;
// 		cout << cur << endl;
// 		return;
// 	}

// 	for (int i = n + 1; i < siz; i++) {
// 		if (N[i] != '0') dfs(i, cnt+1, cur * (N[i] - '0'));
// 	}
// }

// void solve(std::string N, long long K){
// 	siz = N.size();
// 	REP (i, siz-1) {
// 		long long cnt = 1;
// 		REP (j, K-1) cnt *= (i - j);
// 		REP (j, K-1) cnt /= j + 1;
		
// 		REP (i, K) cnt *= 9;
// 		ans += cnt;
// 	}
// 	cout << ans << endl;

// 	if (K == 1) {
// 		bool flag = 1;
// 		for (int i = 1; i < siz; i++) if (N[i] != '0') flag = 0;
// 		if (flag) ans += N[0] - '0';
// 	} else {
// 		for (int i = 1; i < siz; i++) {
// 			if (N[i] != '0') dfs(i, 1, 9 * (N[0] - '1') + (N[i] - '0'));
// 			else ans += 9 * (N[0] - '1');
// 		}
// 	}

// 	cout << ans << endl;
// }
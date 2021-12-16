#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define MOD 1000000007
#define ll long long
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
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


void solve(long long N, std::vector<long long> A){
	vector<vector<ll>> dp(N, vector<ll>(2, -INF64));
	dp[0][0] = 0;

	REP (i, N) {
		for (int j = i/2+1; j >= max(0, i/2-3); j--) {
			if (dp[j][0] != -INF64) {
				// A[i]を選ぶ場合
				chmax(dp[j + 1][1], dp[j][0] + A[i]);
			}

			// A[i]を選ばない場合
			chmax(dp[j][0], max(dp[j][0], dp[j][1]));
		}
	}

	cout << max(dp[N/2][0], dp[N/2][1]) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

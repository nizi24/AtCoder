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


void solve(long long R, long long C, long long K, std::vector<long long> r, std::vector<long long> c, std::vector<long long> v){
    vector<vector<long long>> G(R, vector<long long>(C, 0));
    REP (i, K) G[r[i]-1][c[i]-1] = v[i];

    vector<vector<vector<long long>>> dp(R+1, vector<vector<long long>>(C+1, vector<long long>(4, 0)));
    REP (i, R) {
        REP (j, C) {
            REP (k, 4) {
                if (G[i][j] != 0 && k != 3) {
                    chmax(dp[i + 1][j][0], dp[i][j][k] + G[i][j]); // アイテムを拾って上に行く
                    chmax(dp[i][j + 1][k + 1], dp[i][j][k] + G[i][j]); // アイテムを拾って右に行く
                }

                chmax(dp[i + 1][j][0], dp[i][j][k]); // アイテムを拾わず上に行く
                chmax(dp[i][j + 1][k], dp[i][j][k]); // アイテムを拾わず右に行く
            }
        }
    }

    long long ans = 0;
    REP (i, 4) {
        chmax(ans, dp[R][C-1][i]);
    }

    cout << ans << endl;
}

int main(){
    long long R;
    scanf("%lld",&R);
    long long C;
    scanf("%lld",&C);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> r(K);
    std::vector<long long> c(K);
    std::vector<long long> v(K);
    for(int i = 0 ; i < K ; i++){
        scanf("%lld",&r[i]);
        scanf("%lld",&c[i]);
        scanf("%lld",&v[i]);
    }
    solve(R, C, K, std::move(r), std::move(c), std::move(v));
    return 0;
}

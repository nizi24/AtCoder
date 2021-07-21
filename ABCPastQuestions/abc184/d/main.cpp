#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;



void solve(long long A, long long B, long long C){
	vector<vector<vector<double>>> dp(102, vector<vector<double>>(102, vector<double>(102, 0)));
	dp[A][B][C] = 1;

	for (int i = A; i < 100; i++) {
		for (int j = B; j < 100; j++) {
			for (int k = C; k < 100; k++) {
				double I = i, J = j, K = k, N = i+j+k;
				dp[i + 1][j][k] += dp[i][j][k] * I/N;
				dp[i][j + 1][k] += dp[i][j][k] * J/N;
				dp[i][j][k + 1] += dp[i][j][k] * K/N;
			}
		}
	}

	double ans = 0;
	REP (i, 100) {
		REP (j, 100) {
			int n = 100+i+j-(A+B+C);
			ans += n * (dp[100][i][j] + dp[i][100][j] + dp[i][j][100]);
		}
	}

	cf(ans)

}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    solve(A, B, C);
    return 0;
}

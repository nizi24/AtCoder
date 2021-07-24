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

const long long MOD = 1000000007;

long long modPow(long long a, long long N) {
	long long ans = 1;
	REP (i, N) {
		ans *= a;
		ans %= MOD;
	}
	return ans % MOD;
}

void solve(long long N){
	long long ans = modPow(10, N) - modPow(9, N) - modPow(9, N) + modPow(8, N);
	ans %= MOD;
	ans = (ans+MOD) % MOD;
	cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

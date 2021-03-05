#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
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


void solve(long long K){
	ll ans = 0;
	REP (i, K) {
		REP (j, K) {
			REP (k, K) {
				ll cur = (i + 1);
				cur = gcd(gcd(j + 1, k + 1), cur);
				ans += cur;
			}
		}
	}
	cout << ans << endl;
}

int main(){
    long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}

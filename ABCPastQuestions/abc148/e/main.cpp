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


void solve(long long N){
	if (N % 2 == 0) {
		long long ans = 0;
		int cnt = 1;
		long long p = pow(5, cnt);
		while (p <= N) {
			ans += N / p / 2;
			cnt++;
			p = pow(5, cnt);
			// cout << p << endl;
			if (cnt > 25) break;
		}
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

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


void solve(long long X){
	long long ans = 0;
	while (ans == 0) {
		bool brk = false;
		for (int i = 2; i * i <= X; i++) {
			if (X % i == 0) {
				brk = true;
				break;
			}
		}
		if (!brk) ans = X;
		X++;
	}
	cout << ans << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}

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

// long long re(long long H, vector<long long> &memo) {
// 	if (H == 1) return 1;
// 	if (memo[H]) return memo[H];
// 	return memo[H] = re(H / 2, memo) + re(H / 2, memo) + 1;
// }

void solve(long long H){
	// vector<long long> memo(H+10, 0);
	long long ans = 0;
	while (H > 0) {
		ans++;
		H /= 2;
		if (H > 0) {
			ans *= 2;
		}
	}
	cout << ans << endl;
	// cout << re(H, memo) << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    solve(H);
    return 0;
}

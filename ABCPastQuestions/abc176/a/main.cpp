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


void solve(long long N, long long X, long long T){
	int takoyaki = 0;
	int ans = 0;
	while (N > takoyaki) {
		ans += T;
		takoyaki += X;
	}
	cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    long long T;
    scanf("%lld",&T);
    solve(N, X, T);
    return 0;
}

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


void solve(long long X, long long K, long long D){
	long long k = K;
	K -= abs(X / D);
	if (K >= 0) {
		if (K % 2 == 0) cout << abs(X % D);
		else cout << abs(abs(X % D) - D);
	} else {
		cout << abs(abs(X) - k * D);
	}
	cout << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long K;
    scanf("%lld",&K);
    long long D;
    scanf("%lld",&D);
    solve(X, K, D);
    return 0;
}

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


void solve(long long X){
	for (int i = -1000; i < 1000; i++) {
		long long a = pow(i, 5);
		for (long long j = -1000; j < 1000; j++) {
			long long b = pow(j, 5);
			if (a - b == X) {
				cout << i << " " << j << endl;
				return;
			}
		}
	}
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}

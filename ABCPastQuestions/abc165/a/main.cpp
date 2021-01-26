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


void solve(long long K, long long A, long long B){
	int ans = 0;
	for (int i = A; A <= B; A++) {
		if (A % K == 0) {
			ans++;
			break;
		}
	}
	cout << (ans ? "OK" : "NG") << endl;
}

int main(){
    long long K;
    scanf("%lld",&K);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(K, A, B);
    return 0;
}

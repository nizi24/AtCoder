#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
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

long long modpow(long long a, long long n, long long k) {
	if (n == 0) return 1;
        auto t = modpow(a, n / 2, k) % k;
        t = t * t % k;
        if (n & 1) t = t * a % k;
        return t;
}

void solve(long long K){
	vector<long long> k(K+1, 0);
	REP (i, K) {
		k[i+1] = (k[i] + modpow(10LL, i, K) * 7) % K;
		if (!k[i+1]) {
			cout << i+1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(){
	long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}

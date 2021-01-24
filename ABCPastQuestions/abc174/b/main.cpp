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


void solve(long long N, long long D, std::vector<long long> X, std::vector<long long> Y){
    int ans = 0;
    REP (i, N) {
        if (sqrt(X[i] * X[i] + Y[i] * Y[i]) <= D) ans++;
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long D;
    scanf("%lld",&D);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&Y[i]);
    }
    solve(N, D, std::move(X), std::move(Y));
    return 0;
}

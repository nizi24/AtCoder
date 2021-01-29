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

const long long MD = 1000000007;

void solve(long long N, std::vector<long long> A){
	ALL(sort, A);
	long long ans = 0;
	long long sum = 0;
	REP (i, N) sum += A[i];
	long long current_sum = 0;
	REP(i, N) {
		current_sum += A[i];
		if (i != N - 1) {
			__int128_t a = (A[i] * ((sum - current_sum) % MD)) % MD;
			ans += a;
			ans %= MD;
		}
	}
	cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

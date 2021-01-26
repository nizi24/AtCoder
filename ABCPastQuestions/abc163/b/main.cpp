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


void solve(long long N, long long M, std::vector<long long> A){
    int ans = N;
    REP (i, M) ans -= A[i];
    cout << (ans < 0 ? -1 : ans) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, M, std::move(A));
    return 0;
}

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


void solve(long long N, long long K, std::vector<long long> A){
    long long sm = 0;
    REP (i, N) sm += A[i];

    long long ok = sm;
    long long ng = 0;
    while (ok - ng > 1) {
        long long mid = (ok + ng) / 2;

        long long cnt = 0;
        REP (i, N) {
            cnt += (A[i]-1)/mid;
        }

        if (cnt <= K) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}

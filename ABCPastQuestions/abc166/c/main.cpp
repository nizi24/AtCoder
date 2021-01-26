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


void solve(long long N, long long M, std::vector<long long> H, std::vector<long long> A, std::vector<long long> B){
    vector<bool> good(N, true);
    REP(i, M) {
        if (H[A[i] - 1] > H[B[i] - 1]) good[B[i] - 1] = false;
        else if (H[A[i] - 1] < H[B[i] - 1]) good[A[i] - 1] = false;
        else {
            good[A[i] - 1] = false;
            good[B[i] - 1] = false;
        }
    }
    int ans = 0;
    REP (i, N) if (good[i]) ans++;
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, M, std::move(H), std::move(A), std::move(B));
    return 0;
}

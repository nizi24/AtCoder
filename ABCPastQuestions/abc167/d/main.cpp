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
    vector<vector<long long>> db(100, vector<long long>(N));
    REP (i, N) A[i]--;
    REP (i, N) db[0][i] = A[i];
    REP (i, 99) {
        REP (j, N) db[i + 1][j] = db[i][db[i][j]];
    }
    long long now = 0;
    for (int k = 0; K > 0; k++) {
        if (K & 1) now = db[k][now];
        K >>= 1;
    }
    cout << now + 1 << endl;
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

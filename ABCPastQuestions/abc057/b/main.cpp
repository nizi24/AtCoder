#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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
#define INF64 INT64_MAX / 2


void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    REP (i, N) {
        long long min = INF64;
        long long cnt = 0;
        REP (j, M) {
            long long dif = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (chmin(min, dif)) cnt = j + 1;
        }
        cout << cnt << endl;
    }   
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> c(M);
    std::vector<long long> d(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, M, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}

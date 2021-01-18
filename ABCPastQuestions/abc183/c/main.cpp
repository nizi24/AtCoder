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


void solve(long long N, long long K, std::vector<std::vector<long long>> T){
    int ans = 0;
    vector<int> ids;
    REP(i, N-1) ids.push_back(i+1);
    do {
        int dis = 0;
        int from = 0;
        for (int id : ids) {
            dis += T[from][id];
            from = id;
        }
        dis += T[from][0];
        if (dis == K) ans++;
    } while (next_permutation(ids.begin(), ids.end()));
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<std::vector<long long>> T(N, std::vector<long long>(N));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%lld",&T[i][j]);
        }
    }
    solve(N, K, std::move(T));
    return 0;
}

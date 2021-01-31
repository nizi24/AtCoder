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
template<class T>
inline T sum(T n){return n*(n+1)/2;}


void solve(long long N, std::vector<long long> P, std::vector<long long> Q){
    vector<int> n;
    REP (i, N) n.push_back(i+1);
    int a = -1;
    int b = -1;
    int j = 1;
    do {
        if (a == -1) {
            bool ok = true;
            REP (i, N) if (P[i] != n[i]) ok = false;
            if (ok) a = j;
        }
        if (b == -1) {
            bool ok = true;
            REP (i, N) if (Q[i] != n[i]) ok = false;
            if (ok) b = j;
        }
        j++;
    } while(next_permutation(n.begin(), n.end()));
    cout << abs(a - b) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
    }
    std::vector<long long> Q(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&Q[i]);
    }
    solve(N, std::move(P), std::move(Q));
    return 0;
}

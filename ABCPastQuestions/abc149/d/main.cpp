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


void solve(long long N, long long K, long long R, long long S, long long P, std::string T){
    vector<vector<long long>> dp(N+10, vector<long long>(3, 0));
    REP (i, 3) dp[0][i] = 0;
    map<char, pair<long long, long long>> pnt;
    pnt['r'] = {2, P};
    pnt['s'] = {0, R};
    pnt['p'] = {1, S};
    // TODO: DPで解く

    long long max = 0;
    REP (i, 3) chmax(max, dp[N][i]);
    cout << max << endl;

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    long long R;
    scanf("%lld",&R);
    long long S;
    scanf("%lld",&S);
    long long P;
    scanf("%lld",&P);
    std::string T;
    std::cin >> T;
    solve(N, K, R, S, P, T);
    return 0;
}

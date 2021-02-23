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
    long long ans = 0;
    map<char, pair<char, long long>> point;
    point['r'] = {'p', P};
    point['s'] = {'r', R};
    point['p'] = {'s', S};
    vector<char> vec(N);
    REP (i, N) {
        if (K > i || vec[i - K] != point[T[i]].first) {
            ans += point[T[i]].second;
            vec[i] = point[T[i]].first;
        } else {
            vec[i] = ' ';
        }
    }
    cout << ans << endl;
}

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

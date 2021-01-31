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


void solve(long long N, long long M, std::vector<long long> s, std::vector<long long> c){
    string ans = "";
    set<pair<int, int>> st;
    REP (i, M) st.insert(make_pair(s[i], c[i]));
    REP (i, N) {
        int add = 0;
        for (auto s : st) {
            if (add && add != s.second && s.first == i + 1) {
                cout << -1 << endl;
                return;   
            }
            if (s.first == i + 1) {
                if (s.first == 1 && s.second == 0 && N != 1) {
                    cout << -1 << endl;
                    return;
                }
                ans += to_string(s.second);
                add = s.second;
                if (s.second == 0) add++;
            }
        }
        if (!add) {
            if (i == 0) {
                if (N == 1) ans += "0";
                else ans += "1";
            }
            else ans += "0";
        }
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> s(M);
    std::vector<long long> c(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&s[i]);
        scanf("%lld",&c[i]);
    }
    solve(N, M, std::move(s), std::move(c));
    return 0;
}

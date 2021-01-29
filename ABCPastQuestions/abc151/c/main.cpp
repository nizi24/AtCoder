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

bool str(pair<int, string> A, pair<int, string> B) {
    if (A.first < B.first) return true;
    return false;
}

void solve(long long N, long long M, std::vector<long long> p, std::vector<std::string> S){
    map<long long, pair<int, int>> mp;
    REP (i, M) {
        mp[p[i]].first += (S[i] == "AC");
        if (mp[p[i]].first == 0) {
            mp[p[i]].second += (S[i] == "WA");
        }
    }
    int ac = 0;
    int miss = 0;
    for (auto m : mp) {
        if (m.second.first > 0) {
            ac++;
            miss += m.second.second;
        }
    }
    cout << ac << " " << miss << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> p(M);
    std::vector<std::string> S(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&p[i]);
        std::cin >> S[i];
    }
    solve(N, M, std::move(p), std::move(S));
    return 0;
}

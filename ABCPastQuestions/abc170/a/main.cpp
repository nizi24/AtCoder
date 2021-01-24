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


void solve(std::vector<long long> x){
	REP (i, 5) if (x[i] == 0) cout << i + 1 << endl;
}

int main(){
    std::vector<long long> x(5);
    for(int i = 0 ; i < 5 ; i++){
        scanf("%lld",&x[i]);
    }
    solve(std::move(x));
    return 0;
}

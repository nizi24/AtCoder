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


void solve(long long N, std::vector<std::string> S){
	int ac = 0;
	int wa = 0;
	int tle = 0;
	int re = 0;
	REP (i, N) {
		string str = S[i];
		if (str == "AC") {
			ac++;
		} else if (str == "WA") {
			wa++;
		} else if (str == "TLE") {
			tle++;
		} else if (str == "RE") {
			re++;
		}
	}
	printf("AC x %d\n", ac);
	printf("WA x %d\n", wa);
	printf("TLE x %d\n", tle);
	printf("RE x %d\n", re);
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> S(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}

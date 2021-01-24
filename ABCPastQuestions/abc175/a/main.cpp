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


void solve(std::string S){
	int ans = 0;
	bool a = S[0] == 'R';
	bool b = S[1] == 'R';
	bool c = S[2] == 'R';
	if (a) {
		ans++;
		if (b){
			ans++;
			if (c) ans++;
		}
	} else if (b) {
		ans++;
		if (c) ans++;
	} else if (c) ans++;
	cout << ans << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

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
	if (S.at(0) == 'R') {
		ans++;
		if (S.at(1) == 'R') {
			ans++;
			if (S.at(2) == 'R') {
				ans++;
			}
		}
	} else if (S.at(1) == 'R') {
		ans++;
		if (S.at(2) == 'R') {
			ans++;
		}
	} else if (S.at(2) == 'R') {
		ans++;
	}
	cout << ans << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

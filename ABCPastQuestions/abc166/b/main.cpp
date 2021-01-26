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



int main(){
	int N, K;
	cin >> N >> K;
	vector<bool> t(N, false);
	REP (k, K) {
		int d;
		cin >> d;
		REP (j, d) {
			int i;
			cin >> i;
			t[i - 1] = true;
		}
	}
	int ans = 0;
	REP (i, N) if (!t[i]) ans++;
	cout << ans << endl;
    return 0;
}

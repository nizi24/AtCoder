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
    long long H, W, K;
	cin >> H >> W >> K;
	vector<string> str(H);
	REP (i, H) cin >> str[i];
	int ans = 0;
	for (int bit1 = 0; bit1 < (1 << H); bit1++) {
		for (int bit2 = 0; bit2 < (1 << W); bit2++) {
			int black_count = 0;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					if (bit2 & (1 << j) && bit1 & (1 << i)) {
						if (str[i][j] == '#') black_count++;
					}
				}
			}
			if (black_count == K) {
				ans++;
				// cout << "bit1=" << bit1 << " bit2=" << bit2 << endl;
			}
		}
	}
	cout << ans << endl;
    return 0;
}

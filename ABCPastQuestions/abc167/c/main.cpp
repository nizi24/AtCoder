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
    long long N, M, X;
	cin >> N >> M >> X;
	vector<long long> c(N);
	vector<vector<long long>> A(N, vector<long long>(M));
	REP (i, N) {
		cin >> c[i];
		REP (j, M) cin >> A[i][j];
	}
	long long min = INF;
	for (int bit = 0; bit < (1 << N); bit++) {
		vector<long long> current_M(M, 0);
		long long current_sum = 0;
		for (int i = 0; i < N; i++) {
			if (bit & (1 << i)) {
				REP (j, M) current_M[j] += A[i][j];
				current_sum += c[i];
			}
		}
		bool ctn = false;
		REP (i, M) {
			if (current_M[i] < X) {
				ctn = true;
				break;
			}
		}
		if (ctn) continue;
		chmin(min, current_sum);
	}
	if (min == INF) cout << -1 << endl;
	else cout << min << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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


void solve(long long K, long long S){
	int ans = 0;
	for (int i = 0; i < K+1; i++) {
		for (int j = 0; j < K+1; j++) {
			if (S - (i+j) <= K && S - (i+j) >= 0) ans++;
		}
	}
	cout << ans << endl;
}

int main(){
    long long K;
    scanf("%lld",&K);
    long long S;
    scanf("%lld",&S);
    solve(K, S);
    return 0;
}

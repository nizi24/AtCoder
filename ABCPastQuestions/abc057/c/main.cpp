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


void solve(long long N){
	map<i64, i64> mp;
	for (i64 i = 1; i * i <= N; i++) {
		if (N % i == 0) mp[i] = N/i;
	}
	i64 min = -1;
	for (auto m : mp) {
		i64 fs = to_string(m.first).size();
		i64 ss = to_string(m.second).size();
		i64 f = fs > ss ? fs : ss;
		if (min != -1) {
			chmin(min, f);
		} else {
			min = f;
		}
	}
	cout << min << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

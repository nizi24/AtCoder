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
	stack<i64> res;
	for (i64 i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			cout << i << endl;
			if (i != N/i) res.push(N/i);
		}
	}
	int size = res.size();
	REP(i, size) {
		cout << res.top() << endl;
		res.pop();
	}
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

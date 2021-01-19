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


void solve(long long N, std::vector<long long> x){
	i64 ans1 = 0, ans3 = 0;
	double ans2 = 0;
	REP (i, N) {
		i64 x_abs = abs(x.at(i));
		ans1 += x_abs;
		ans2 += x_abs * x_abs;
		ans3 = max(abs(ans3), x_abs);
	}
	cout << ans1 << endl;
	ans2 = sqrt(ans2);
	cout << fixed << setprecision(15) << ans2 << endl;
	cout << ans3 << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
    }
    solve(N, std::move(x));
    return 0;
}

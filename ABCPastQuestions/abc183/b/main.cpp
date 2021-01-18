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


void solve(long long S_x, long long S_y, long long G_x, long long G_y){
    double x = G_x - S_x;
    double y = abs(S_y) + abs(G_y);
    double per = abs(S_y) / y;
    double X = x * per + S_x;
    cout << fixed << setprecision(15) << X << endl;
}

int main(){
    long long S_x;
    scanf("%lld",&S_x);
    long long S_y;
    scanf("%lld",&S_y);
    long long G_x;
    scanf("%lld",&G_x);
    long long G_y;
    scanf("%lld",&G_y);
    solve(S_x, S_y, G_x, G_y);
    return 0;
}

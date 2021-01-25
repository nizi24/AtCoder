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


void solve(long long N){
	string str = to_string(N);
	string hon = "24579";
	string pon = "0168";
	string bon = "3";
	REP (i, 5) if (hon[i] == str[str.size()-1]) cout << "hon" << endl;
	REP (i, 4) if (pon[i] == str[str.size()-1]) cout << "pon" << endl;
	if ('3' == str[str.size()-1]) cout << "bon" << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

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

const string YES = "Yes";
const string NO = "No";

void solve(long long D, long long T, long long S){
	if (S * T >= D) {
		cout << YES << endl;
	} else {
		cout << NO << endl;
	}
}

int main(){
    long long D;
    scanf("%lld",&D);
    long long T;
    scanf("%lld",&T);
    long long S;
    scanf("%lld",&S);
    solve(D, T, S);
    return 0;
}

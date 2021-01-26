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
template<class T>
inline T sum(T n){return n*(n+1)/2;}

const string YES = "Yes";
const string NO = "No";

void solve(std::string S) {
	string rev(S);
	ALL(reverse, rev);
	string S2 = S.substr(0, (S.size()-1)/2);
	string rev2(S2);
	ALL(reverse, S2);
	string S3 = S.substr((S.size()+3)/2-1);
	string rev3(S3);
	ALL(reverse, S3);
	if (S == rev && rev2 == S2 && rev3 == S3) cout << YES << endl;
	else cout << NO << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

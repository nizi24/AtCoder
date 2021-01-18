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

void is_surplus_equal(char c, int i) {
	stoi(to_string(c)) % 3 == i;
}

void solve(long long N){
	string str = to_string(N);
	int ans = -1;
	int n = 0;
	int sum = 0;
	REP(i, str.size()) {
		sum += stoi(to_string(str.at(i)));
	}
	int surplus = sum % 3;
	if (surplus != 0) {
		if (str.size() > 2) {
			n = 2;
		}
		for (auto c : str) {
			if (stoi(to_string(c)) % 3 == surplus && str.size() > 1) {
				n = 1;
				break;
			}
		}
		if (n == 0) {
			n = -1;
		}
	}
	cout << n << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

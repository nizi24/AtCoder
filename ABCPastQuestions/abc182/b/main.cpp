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



int main(){
    int n;
	cin >> n;
	vector<int> ary(n);
	REP(i, n) cin >> ary.at(i);
	map<int, int> count;
	for (auto a : ary) {
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				if (i != 1)	count[i]++;
				if (i != a/i) count[a/i]++;
			}
		}
	}
	int max_key = 0;
	int max_value = 0;
	for (auto c : count) {
		if (chmax(max_value, c.second)) max_key = c.first;
	}
	cout << max_key << endl;
    return 0;
}

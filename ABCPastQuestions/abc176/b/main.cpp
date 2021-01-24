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

const string YES = "Yes";
const string NO = "No";

void solve(std::string N){
	int sum = 0;
	REP (i, N.size()) {
		string n{N[i]};
		sum += stoi(n);
	}
	cout << (sum % 9 == 0 ? "Yes" : "No") << endl;
}

int main(){
    std::string N;
    std::cin >> N;
    solve(N);
    return 0;
}

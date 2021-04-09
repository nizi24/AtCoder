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

void solve(string S){
	if (S.size() < 3) {
		if (stoi(S) % 8 == 0) {
			cout << YES << endl;
		} else {
			ALL(reverse, S);
			if (stoi(S) % 8 == 0) cout << YES << endl;
			else cout << NO << endl;
		}

		return;
	}

	map<int, int> cnt;

	REP (i, S.size()) {
		cnt[S[i] - '0']++;
	}

	for (int i = 1; i <= 9; i++) {
		if (cnt[i]) cnt[i]--;
		else continue;

		for (int j = 1; j <= 9; j++) {
			if (cnt[j]) cnt[j]--;
			else continue;

			for (int k = 1; k <= 9; k++) {

				if (cnt[k]) cnt[k]--;
				else continue;

				int cur = i * 100 + j * 10 + k;

				if (cur % 8 == 0) {
					// cout << cur << endl;
					cout << YES << endl;
					return;
				}

				cnt[k]++;
			}
			cnt[j]++;
		}
		cnt[i]++;
	}

	cout << NO << endl;
}

int main(){
    string S;
    cin >> S;
    solve(S);
    return 0;
}

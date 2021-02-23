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

vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

void solve(long long N, std::string S){
	long long cnt = 0;
	long long r = 0;
	long long g = 0;
	long long b = 0;
	REP (i, N) {
		if (S[i] == 'R') r++;
		if (S[i] == 'G') g++;
		if (S[i] == 'B') b++;
		for (int j = 1; i + j * 2 < N; j++) {
			if (S[i] != S[i + j] && S[i + j] != S[i + j * 2] && S[i] != S[i + j * 2]) cnt++;
		}
	}
	cout << r * g * b - cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}

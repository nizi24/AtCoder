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

void solve(long long A, long long B){
	int left = 0;
	int right = INF;
	int boader10_begin = -1;
	int boader8_begin = -1;
	int boader10_end = -1;
	int boader8_end = -1;
	while (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tax8 = mid * 0.08;
		if (tax8 >= A) right = mid;
		else left = mid;
		if (tax8 == A) boader8_begin = mid;
	}
	left = 0;
	right = INF;
	while (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tax10 = mid * 0.1;
		if (tax10 >= B) right = mid;
		else left = mid;
		if (tax10 == B) boader10_begin = mid;
	}
	left = 0;
	right = INF;
	while (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tax8 = mid * 0.08;
		if (tax8 > A) right = mid;
		else left = mid;
		if (tax8 == A) boader8_end = mid;
	}
	left = 0;
	right = INF;
	while (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tax10 = mid * 0.1;
		if (tax10 > B) right = mid;
		else left = mid;
		if (tax10 == B) boader10_end = mid;
	}
	int ans = -1;
	for (int i = boader8_begin; i <= boader8_end; i++) {
		bool bre = false;
		for (int j = boader10_begin; j <= boader10_end; j++) {
			if (i == j) {
				ans = i;
				bre = true;
				break;
			}
		}
		if (bre) break;
	}
	cout << ans << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}

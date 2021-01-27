#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
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
template<class T>
inline void rp(map<T, T> &mp, long long A) {
	for (int i = 2; i * i <= A; i++) {
		while (A % i == 0) {
			mp[i]++;
			A /= i;
		}
	}
	if (A != 1) mp[A] = 1;
}

void solve(long long A, long long B){
	map<int, int> mpA;
	map<int, int> mpB;
	rp(mpA, A);
	rp(mpB, B);
	long long ans = 1;
	for (int i = 2; i <= max(A, B); i++) {
		int max = 0;
		chmax(max, mpA[i]);
		chmax(max, mpB[i]);
		while (max > 0) {
			ans *= i;
			max--;
		}
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

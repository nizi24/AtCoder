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


void solve(std::string S, std::string T, long long A, long long B, std::string U){
    if (S == U) A--;
    else B--;
    printf("%d %d\n", A, B);
}

int main(){
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    std::string U;
    std::cin >> U;
    solve(S, T, A, B, U);
    return 0;
}

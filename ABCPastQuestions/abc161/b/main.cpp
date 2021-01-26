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

void solve(long long N, long long M, std::vector<long long> A, long long sum){
    ALL(sort, A);
    string ans = "Yes";
    REP(i, M) if (sum > A[A.size()-i-1] * M * 4) ans = "No";
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(N);
    long long sum = 0;
    for(int i = 0 ; i < N ; i++){
        long long ii;
        scanf("%lld",&ii);
        sum += ii;
        A[i] = ii;
    }
    solve(N, M, std::move(A), sum);
    return 0;
}

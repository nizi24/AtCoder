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
#define INF64 INT64_MAX / 2


void solve(long long N, std::vector<long long> A, std::vector<long long> B){
    vector<long long> mins, maxs;
    REP (i, N) {
        mins.push_back(A[i]);
        maxs.push_back(B[i]);
    }

    ALL(sort, mins);
    ALL(sort, maxs);

    if (N % 2 != 0) {
        int mid = N/2;
        cout << maxs[mid] - mins[mid] + 1 << endl;
    } else {
        int mid1 = N/2;
        int mid2 = mid1-1;
        cout << (maxs[mid1] + maxs[mid2]) - (mins[mid1] + mins[mid2]) + 1 << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(A), std::move(B));
    return 0;
}

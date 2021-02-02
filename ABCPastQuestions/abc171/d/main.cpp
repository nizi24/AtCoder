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


void solve(long long N, std::vector<long long> A, long long Q, std::vector<long long> B, std::vector<long long> C){
    map<long long, long long> mp;
    long long sum = 0;
    REP (i, N) {
        mp[A[i]]++;
        sum += A[i];
    }
    REP (i, Q) {
        long long b = mp[B[i]];
        sum -= B[i] * b;
        sum += C[i] * b;
        mp[C[i]] += b;
        mp[B[i]] = 0;
        cout << sum << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> B(Q);
    std::vector<long long> C(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
    }
    solve(N, std::move(A), Q, std::move(B), std::move(C));
    return 0;
}

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


void solve(long long N, std::vector<long long> A){
	vector<long long> p(1000001, 0);
	vector<bool> seen(1000001, 0);

	bool ok = 1;
	REP (i, N) {
		if (p[A[i]] && A[i] != 1) ok = 0;
		p[A[i]]++;
	}

	if (ok) {
		for (int i = 2; i <= 1000000; i++) {
			if (seen[i]) continue;

			bool one = 0;
			for (int j = i; j <= 1000000; j += i) {
				if (one && p[j]) {
					ok = 0;
				}

				seen[j] = 1;
				if (p[j]) one = 1;
			}
		}
	}

	if (ok) cout << "pairwise coprime" << endl;
	else {
		long long GCD = A[0];
		REP (i, N) GCD = __gcd(GCD, A[i]);

		if (GCD == 1) cout << "setwise coprime" << endl;
		else cout << "not coprime" << endl;
	}
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

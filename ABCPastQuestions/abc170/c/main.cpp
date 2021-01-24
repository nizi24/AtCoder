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


void solve(long long X, long long N, std::vector<long long> p){
    long long abs_min = INF;
    long long res = X;
    int ary_length = p.size();
    ALL(sort, p);
    if (ary_length) {
        for (int i = 200; i >= 0; i--) {
            if (ary_length && p[ary_length - 1] == i) {
                p.pop_back();
                ary_length--;
            } else if (abs_min == abs(X - i)){
                res = i;
            } else {
                if (chmin(abs_min, abs(X - i))) {
                    res = i;
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> p(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&p[i]);
    }
    solve(X, N, std::move(p));
    return 0;
}

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

void solve(long long N, std::vector<std::vector<long long>> D){
    string res = NO;
    REP (i, N-2) {
        if (D.at(i).at(0) == D.at(i).at(1)) {
            if (D.at(i+1).at(0) == D.at(i+1).at(1)) {
                if (D.at(i+2).at(0) == D.at(i+2).at(1)) {
                    res = YES;
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::vector<long long>> D(N, std::vector<long long>(2));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < 2 ; j++){
            scanf("%lld",&D[i][j]);
        }
    }
    solve(N, std::move(D));
    return 0;
}

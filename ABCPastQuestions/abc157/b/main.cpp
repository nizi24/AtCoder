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

void solve(std::vector<std::vector<long long>> A, long long N, std::vector<long long> b){
    vector<vector<bool>> bingo(3, vector<bool>(3, false));
    REP (i, N) REP (j, 3) REP(k, 3) if(b[i] == A[j][k]) bingo[j][k] = true;
    string ans = NO;
    REP (i, 3) {
        if (bingo[i][0] && bingo[i][1] && bingo[i][2]) ans = YES;
        if (bingo[0][i] && bingo[1][i] && bingo[2][i]) ans = YES;
    }
    if (bingo[0][0] && bingo[1][1] && bingo[2][2]) ans = YES;
    if (bingo[0][2] && bingo[1][1] && bingo[2][0]) ans = YES;
    cout << ans << endl;
}

int main(){
    std::vector<std::vector<long long>> A(3, std::vector<long long>(3));
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    long long N;
    scanf("%lld",&N);
    std::vector<long long> b(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&b[i]);
    }
    solve(std::move(A), N, std::move(b));
    return 0;
}

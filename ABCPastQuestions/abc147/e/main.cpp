#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}


void solve(long long H, long long W, std::vector<std::vector<long long>> A, std::vector<std::vector<long long>> B){
    int MAX = 80 * 160 * 2 + 1;
    vector<vector<vector<int>>> dp(H, vector<vector<int>>(W, vector<int>(MAX, 0)));
    dp[0][0][80 * 160 + 1 + A[0][0] - B[0][0]] = 1;

    REP (i, H) {
        REP (j, W) {
            REP (k, MAX) {
                if (i + 1 < H) {
                    int nx1 = k + A[i + 1][j] - B[i + 1][j];
                    int nx3 = k - A[i + 1][j] + B[i + 1][j];
                    if (nx1 >= 0 && nx1 < MAX) {
                        dp[i + 1][j][nx1] |= dp[i][j][k];
                    }
                    if (nx3 >= 0 && nx3 < MAX) {
                        dp[i + 1][j][nx3] |= dp[i][j][k];
                    }
                }

                if (j + 1 < W) {
                    int nx2 = k + A[i][j + 1] - B[i][j + 1];
                    int nx4 = k - A[i][j + 1] + B[i][j + 1];
                    if (nx2 >= 0 && nx2 < MAX) {
                        dp[i][j + 1][nx2] |= dp[i][j][k];
                    }
                    if (nx4 >= 0 && nx4 < MAX) {
                        dp[i][j + 1][nx4] |= dp[i][j][k];
                    }
                }
            }
        }
    }

    int ans = INF;
    REP (i, MAX) {
        if (dp[H-1][W-1][i]) {
            chmin(ans, abs(i - (80 * 160 + 1)));
        }
    }

    cout << ans << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::vector<long long>> A(H, std::vector<long long>(W));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    std::vector<std::vector<long long>> B(H, std::vector<long long>(W));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            scanf("%lld",&B[i][j]);
        }
    }
    solve(H, W, std::move(A), std::move(B));
    return 0;
}

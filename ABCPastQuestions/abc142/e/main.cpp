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
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}



int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<vector<ll>> c(M);
    REP (i, M) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        REP (j, b[i]) cin >> c[i][j];
    }

    vector<vector<ll>> dp(M+1, vector<ll>((1 << N), INF));
    dp[0][0] = 0;

    REP (i, M) {
        REP (j, (1 << N)) {
            chmin(dp[i+1][j], dp[i][j]);

            ll x = j;
            REP (k, b[i]) {
                x |= (1 << (c[i][k]-1));
            }
            chmin(dp[i+1][x], dp[i][j] + a[i]);
        }
    }

    cout << (dp[M][(1<<N)-1] == INF ? -1 : dp[M][(1<<N)-1]) << endl;

    return 0;
}

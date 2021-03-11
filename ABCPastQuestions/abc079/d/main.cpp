#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define MD 1000000007
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

void solve(long long H, long long W, std::vector<std::vector<long long>> C, std::vector<std::vector<long long>> A){
    vector<vector<ll>> dp(10, vector<ll>(10, INF));
    REP (i, 10) {
        REP (j, 10) {
            dp[i][j] = C[i][j];
        }
    }

    REP (k, 10)
        REP (i, 10)
            REP (j, 10)
                chmin(dp[i][j], dp[i][k] + dp[k][j]);

    ll ans = 0;
    REP (i, H) {
        REP (j, W) {
            if (A[i][j] == -1 || A[i][j] == 1) continue;

            ans += dp[A[i][j]][1];
        }
    }
    c(ans)
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::vector<long long>> C(9-0+1, std::vector<long long>(9-0+1));
    for(int i = 0 ; i < 9-0+1 ; i++){
        for(int j = 0 ; j < 9-0+1 ; j++){
            scanf("%lld",&C[i][j]);
        }
    }
    std::vector<std::vector<long long>> A(H, std::vector<long long>(W));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    solve(H, W, std::move(C), std::move(A));
    return 0;
}

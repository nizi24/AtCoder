#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define EPS14  1.0E-14
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

long long N;
long long rec(int S, int v, vector<vint> &memo, vector<vint> &G) {
    if (S == 0) {
       if (v == 0) return 0;
       else return INF64;
    }

    if (!(S & (1 << v))) return INF64;
    if (memo[S][v] != INF64) return memo[S][v];

    REP (i, N) {
        chmin(memo[S][v], rec(S & ~(1<<v), i, memo, G) + G[i][v]);
    }

    return memo[S][v];
}

void solve(long long N, std::vector<long long> X, std::vector<long long> Y, std::vector<long long> Z){
    vector<vector<ll>> memo((1 << N), vector<ll>(N, INF64));
    vector<vector<ll>> G(N, vector<ll>(N, INF64));
    REP (i, N) REP (j, N) G[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0LL, Z[j] - Z[i]);

    c(rec((1 << N)-1, 0, memo, G))
    
}

int main(){
    scanf("%lld",&N);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    std::vector<long long> Z(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&Y[i]);
        scanf("%lld",&Z[i]);
    }
    solve(N, std::move(X), std::move(Y), std::move(Z));
    return 0;
}

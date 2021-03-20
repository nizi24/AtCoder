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

void solve(long long N) {
    vector<vector<ll>> G(100000 * 2);

    REP (i, N) {
        G[i].push_back(i + 1);

        for (ll j = 1; pw(6, j) <= N; j++) {
            G[i].push_back(pw(6, j) + i);
        }

        for (ll j = 1; pw(9, j) <= N; j++) {
            G[i].push_back(pw(9, j) + i);
        }
    }

    queue<ll> que;
    vector<ll> dist(100000 * 2, INF);
    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        ll v = que.front();
        que.pop();

        for (auto x : G[v]) {
            if (dist[x] != INF) continue;

            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }

    c(dist[N])



    // vector<vector<ll>> dp(13, vector<ll>(N+1, INF));

    // vector<ll> w(12);
    // w[0] = 1;
    // REP (i, 6) w[i + 1] = pw(6, i+1);
    // REP (i, 5) w[i + 7] = pw(9, i+1);
    
    // REP (i, N) dp[0][i] = i;
    // dp[1][1] = 1;
    // REP (i, 12) {
    //     for (int j = 0; j <= N; j++) {
    //         if (j - w[i] >= 0) {
    //             chmin(dp[i + 1][j], dp[i][j - w[i]] + 1);
    //         }
    //         chmin(dp[i + 1][j], dp[i][j]);
    //     }
    // }

    // c(dp[12][N])
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

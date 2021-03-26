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

using Graph = vector<vector<Edge>>;

void dfs(int v, int p, ll sum, vector<ll> &dist, const Graph &G) {
    dist[v] = sum;
    for (auto e : G[v]) {
        if (e.to == p) continue;
        dfs(e.to, v, sum + e.w, dist, G);
    }
}

void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> C, long long Q, long long K, std::vector<long long> x, std::vector<long long> y){
    Graph G(N);
    REP (i, N-1) {
        G[a[i] - 1].push_back({b[i] - 1, C[i]});
        G[b[i] - 1].push_back({a[i] - 1, C[i]});
    }
    K--;

    vector<ll> dist(N, 0);
    dfs(K, -1, 0, dist, G);

    REP (i, Q) {
        c(dist[x[i] - 1] + dist[y[i] - 1])
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    std::vector<long long> C(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&C[i]);
    }
    long long Q;
    scanf("%lld",&Q);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> x(Q);
    std::vector<long long> y(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(a), std::move(b), std::move(C), Q, K, std::move(x), std::move(y));
    return 0;
}

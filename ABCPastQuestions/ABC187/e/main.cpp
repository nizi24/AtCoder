#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define MOD 1000000007
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
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

struct Edge {
    long long to; // 隣接頂点番号
    long long w; // 重み
    Edge(long long to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

long long all_cost = 0;
void dfs1(int n, int p, Graph &G) {
    for (auto g : G[n]) {
        if (g.to == p) {
            all_cost += g.w;
            continue;
        }
        dfs1(g.to, n, G);
    }
}

void dfs2(int n, int p, ll cur, Graph &G, vector<ll> &ans) {

    for (auto g : G[n]) if (g.to == p) cur -= g.w;

    for (auto g : G[n]) {
        if (g.to == p) continue;
        dfs2(g.to, n, cur+g.w, G, ans);
    }

    ans[n] -= all_cost + cur;
}

void solve(long long N, std::vector<long long> a, std::vector<long long> b, long long Q, std::vector<long long> t, std::vector<long long> e, std::vector<long long> x){
    vector<vector<ll>> cost(N-1, vector<ll>(2, 0));
    ll all = 0;
    REP (i, Q) {
        cost[e[i]-1][t[i]-1] += x[i];
        all += x[i];
    }

    Graph G(N);
    REP (i, N-1) {
        G[a[i]-1].push_back({b[i]-1, cost[i][0]});
        G[b[i]-1].push_back({a[i]-1, cost[i][1]});
    }

    dfs1(0, -1, G);
    
    vector<ll> ans(N, all);
    dfs2(0, -1, 0, G, ans);

    REP (i, N) c(ans[i])
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> t(Q);
    std::vector<long long> e(Q);
    std::vector<long long> x(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&e[i]);
        scanf("%lld",&x[i]);
    }
    solve(N, std::move(a), std::move(b), Q, std::move(t), std::move(e), std::move(x));
    return 0;
}

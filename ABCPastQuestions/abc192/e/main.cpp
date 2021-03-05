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
    long long k; // 出発時刻
    Edge(int to, long long w, long long k) : to(to), w(w), k(k) {}
};

using Graph = vector<vector<Edge>>;

void solve(long long N, long long M, long long X, long long Y, std::vector<long long> A, std::vector<long long> B, std::vector<long long> T, std::vector<long long> K){
    Graph g(N+10);
    REP (i, M) {
        g[A[i]].push_back(Edge(B[i], T[i], K[i]));
        g[B[i]].push_back(Edge(A[i], T[i], K[i]));
    }
    vector<ll> dist(N+10, INF64);
    dist[X] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push({dist[X], X});
    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto x : g[v]) {
            if (chmin(dist[x.to], dist[v] + x.w + (dist[v] % x.k == 0 ? 0 : x.k - dist[v] % x.k))) {
                que.push({dist[x.to], x.to});
            }
        }
    }
    if (dist[Y] == INF64) {
        c(-1)
    } else {
        c(dist[Y])
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    std::vector<long long> T(M);
    std::vector<long long> K(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        scanf("%lld",&T[i]);
        scanf("%lld",&K[i]);
    }
    solve(N, M, X, Y, std::move(A), std::move(B), std::move(T), std::move(K));
    return 0;
}

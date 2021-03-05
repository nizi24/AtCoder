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

void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> C){
    Graph G(N+10);
    REP (i, M) C[i] = C[i];
    REP (i, M) G[a[i]].push_back(Edge(b[i], C[i]));
    vector<bool> negative(N+10, false);
    bool neg = false;
    vector<ll> dist(N+10, -INF64);
    dist[1] = 0;
    for (int i = 0; i < N * 2; i++) {
        bool update = false;
        for (int v = 1; v <= N; v++) {
            if (dist[v] == -INF64) continue;

            for (auto x : G[v]) {
                if (chmax(dist[x.to], dist[v] + x.w)) {
                    update = true;
                    if (i >= N) negative[x.to] = true;
                }
                if (i >= N && negative[v]) negative[x.to] = true;
            }
        }
        if (!update) break;
    }
    if (negative[N]) c("inf")
    else {
        c(dist[N])
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    std::vector<long long> C(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&C[i]);
    }
    solve(N, M, std::move(a), std::move(b), std::move(C));
    return 0;
}

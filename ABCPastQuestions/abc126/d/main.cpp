#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
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

struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

void solve(long long N, std::vector<long long> u, std::vector<long long> v, std::vector<long long> w){
    Graph G(N);

    REP (i, N-1) {
        G[u[i] - 1].push_back({v[i] - 1, w[i] % 2});
        G[v[i] - 1].push_back({u[i] - 1, w[i] % 2});
    }

    queue<ll> que;
    vector<ll> dist(N, INF);
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        auto v = que.front();
        que.pop();

        for (auto n : G[v]) {
            if (dist[n.to] != INF) continue;

            dist[n.to] = dist[v] + n.w;
            que.push(n.to);
        }
    }

    REP (i, N) {
        if (dist[i] % 2 == 0) c(0)
        else c(1)
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> u(N-1);
    std::vector<long long> v(N-1);
    std::vector<long long> w(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&u[i]);
        scanf("%lld",&v[i]);
        scanf("%lld",&w[i]);
    }
    solve(N, std::move(u), std::move(v), std::move(w));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
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

void solve(long long N, long long Q, std::vector<long long> a, std::vector<long long> b, std::vector<long long> p, std::vector<long long> x){
    vector<vector<Edge>> G(N+1);
    vector<ll> weight(N+1, 0);
    REP (i, Q) weight[p[i]] += x[i];
    REP (i, N-1) {
        G[a[i]].push_back(Edge(b[i], weight[b[i]]));
        G[b[i]].push_back(Edge(a[i], weight[a[i]]));
    }
    queue<ll> que;
    vector<ll> dist(N+1, -1);
    dist[1] = 0;
    que.push(1);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();

        for (auto x : G[v]) {
            if (dist[x.to] != -1) continue;

            weight[x.to] = weight[v] + x.w;
            dist[x.to] = weight[x.to];
            que.push(x.to);
        }
    }

    REP (i, N) {
        cout << weight[i + 1] << " ";
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> p(Q);
    std::vector<long long> x(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&p[i]);
        scanf("%lld",&x[i]);
    }
    solve(N, Q, std::move(a), std::move(b), std::move(p), std::move(x));
    return 0;
}

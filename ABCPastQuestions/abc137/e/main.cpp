#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
// 辺を表す型，ここでは重みを表す型を long long 型とする
struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

bool bfs(int i, int N, Graph &G) {
    int r = i; // 始点
    vector<long long> dist(N, INF64);
    queue<long long> que;
    que.push(r);
    dist[r] = 0;
    
    while (!que.empty()) {
        long long p = que.front();
        que.pop();
    
        for (auto n : G[p]) {
            if (dist[n.to] == INF64) {
                que.push(n.to);
                dist[n.to] = dist[p] + 1; 
            }
        }
    }

    if (dist[N-1] != INF64) return true;
    else return false;
}

void solve(long long N, long long M, long long P, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
    REP (i, M) C[i] -= P;

    Graph G(N);
    REP (i, M) G[A[i]-1].push_back({B[i]-1, C[i]});

    // iからNへ到達できるか
    vector<int> d(N, 0);
    REP (i, N) d[i] = bfs(i, N, G);

    // ベルマン・フォード法
    bool exist_negative_cycle = false; // 負閉路をもつかどうか
    vector<long long> dist(N, -INF64);
    dist[0] = 0;
    for (int iter = 0; iter < N * 3; ++iter) {
        bool update = false; // 更新が発生したかどうかを表すフラグ
        for (int v = 0; v < N; ++v) {
            // dist[v] = INF のときは頂点 v からの緩和を行わない
            if (dist[v] == -INF64) continue;
            
            for (auto e : G[v]) {
                // 緩和処理を行い，更新されたら update を true にする
                if (chmax(dist[e.to], dist[v] + e.w) && d[v]) {
                    update = true;
                }
            }
        }

        // N 回目反復で更新が行われたならば，負閉路をもつ
        if (iter >= N - 1 && update) exist_negative_cycle = true;
    }
    
    if (exist_negative_cycle) cout << -1 << endl;
    else cout << max(0LL, dist[N-1]) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long P;
    scanf("%lld",&P);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    std::vector<long long> C(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
    }
    solve(N, M, P, std::move(A), std::move(B), std::move(C));
    return 0;
}

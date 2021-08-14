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
    long long to; // 隣接頂点番号
    long long w; // 重み
    Edge(long long to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    REP (i, M) cin >> A[i] >> B[i] >> C[i];

    Graph G(N);
    REP (i, M) G[A[i]-1].push_back({B[i]-1, C[i]});

    REP (i, N) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
        vector<ll> dist(N, INF64);
        que.push({0, i});
        dist[i] = 0;
        ll ans = INF64;

        while (!que.empty()) {
            ll d = que.top().first;
            ll p = que.top().second;
            que.pop();

            if (d > dist[p]) continue;

            for (auto n : G[p]) {
                if (i == n.to) chmin(ans, dist[p] + n.w);

                if (chmin(dist[n.to], dist[p] + n.w)) {
                    que.push({dist[n.to], n.to});
                }
            }
        }

        c((ans == INF64 ? -1 : ans))
    }
    
    return 0;
}

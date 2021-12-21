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

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<int> A(m), B(m);
    REP (i, m) cin >> A[i] >> B[i];
    cin >> k;
    vector<int> K(k);
    REP (i, k) cin >> K[i];

    vector<vector<ll>> G(n);
    REP (i, m) {
        G[A[i]-1].push_back(B[i]-1);
        G[B[i]-1].push_back(A[i]-1);
    }

    vector<vector<ll>> dis(k, vector<ll>(k, INF));

    REP (i, k) {
        int r = K[i]-1; // 始点
        vector<long long> dist(n, INF);
        queue<long long> que;
        que.push(r);
        dist[r] = 0;
        
        while (!que.empty()) {
            long long p = que.front();
            que.pop();
        
            for (auto n : G[p]) {
                if (dist[n] == INF) {
                    que.push(n);
                    dist[n] = dist[p] + 1; 
                }
            }
        }

        REP (j, k) dis[i][j] = dist[K[j]-1];
    }

    vector<vector<ll>> dp((1 << k), vector<ll>(k, INF));
    REP (i, k) dp[1 << i][i] = 1;

    REP (S, (1 << k)) {
        REP (j, k) if (S & (1 << j)) {
            REP (nx, k) {
                if (S & (1 << nx)) continue;

                chmin(dp[S | (1 << nx)][nx], dp[S][j] + dis[j][nx]);
            }
        }
    }

    ll ans = INF;
    REP (i, k) chmin(ans, dp[(1 << k)-1][i]);
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}

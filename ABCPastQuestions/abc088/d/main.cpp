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



int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    REP (i, H) cin >> s[i];

    queue<pair<ll, ll>> que;
    vector<vector<ll>> dist(H, vector<ll>(W, INF));
    dist[0][0] = 0;
    que.push({0, 0});

    while (!que.empty()) {
        auto [y, x] = que.front();
        que.pop();

        // 下
        if (y + 1 < H && s[y + 1][x] != '#') {
            if (dist[y + 1][x] == INF) {
                dist[y + 1][x] = dist[y][x] + 1;
                que.push({y + 1, x});
            }
        }
        // 上
        if (y - 1 >= 0 && s[y - 1][x] != '#') {
            if (dist[y - 1][x] == INF) {
                dist[y - 1][x] = dist[y][x] + 1;
                que.push({y - 1, x});
            }
        }
        // 右
        if (x + 1 < W && s[y][x + 1] != '#') {
            if (dist[y][x + 1] == INF) {
                dist[y][x + 1] = dist[y][x] + 1;
                que.push({y, x + 1});
            }
        }
        // 左
        if (x - 1 >= 0 && s[y][x - 1] != '#') {
            if (dist[y][x - 1] == INF) {
                dist[y][x - 1] = dist[y][x] + 1;
                que.push({y, x - 1});
            }
        }
    }

    ll white = 0;
    REP (i, H) REP (j, W) if (s[i][j] == '.') white++;

    if (dist[H-1][W-1] == INF) {
        c(-1)
    } else {
        c(white - dist[H-1][W-1] - 1)
    }

    return 0;
}

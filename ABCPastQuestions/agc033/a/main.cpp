#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define EPS14  1.0E-14
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}


void solve(long long H, long long W, std::vector<std::string> A){
    vector<vector<ll>> dist(H, vector<ll>(W, INF));

    // first = y, second = x
    queue<pair<ll, ll>> que;
    REP (i, H) {
        REP (j, W) {
            if (A[i][j] == '#') {
                que.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!que.empty()) {
        ll y = que.front().first;
        ll x = que.front().second;
        que.pop();

        for (int i = -1; i <= 1; i += 2) {
            if (y + i >= 0 && y + i < H && dist[y + i][x] == INF) {
                que.push({y + i, x});
                dist[y + i][x] = dist[y][x] + 1;
            }

            if (x + i >= 0 && x + i < W && dist[y][x + i] == INF) {
                que.push({y, x + i});
                dist[y][x + i] = dist[y][x] + 1;
            }
        }
    }

    ll mx = 0;
    REP (i, H) {
        REP (j, W) {
            chmax(mx, dist[i][j]);
        }
    }

    c(mx)
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::string> A(H);
    for(int i = 0 ; i < H; i++){
        std::cin >> A[i];
    }
    solve(H, W, std::move(A));
    return 0;
}

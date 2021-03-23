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

ll H, W;
vector<string> C;

void dfs(int x, int y, vector<vector<bool>> &seen) {
    seen[y][x] = true;

    for (int i = -1; i <= 1; i += 2) {
        if (x + i < 0 || x + i >= W) continue;
        if (C[y][x + i] == '#') continue;
        if (seen[y][x + i]) continue;

        dfs(x + i, y, seen);
    }

    for (int i = -1; i <= 1; i += 2) {
        if (y + i < 0 || y + i >= H) continue;
        if (C[y + i][x] == '#') continue;
        if (seen[y + i][x]) continue;

        dfs(x, y + i, seen);
    }
}

int main() {
    cin >> H >> W;
    C.resize(H);
    REP (i, H) cin >> C[i];
    vector<vector<bool>> seen(H, vector<bool>(W, false));

    ll hs, ws, hg, wg;

    REP (i, H) {
        REP (j, W) {
            if (C[i][j] == 's') hs = i, ws = j;
            if (C[i][j] == 'g') hg = i, wg = j;
        }
    }

    dfs(ws, hs, seen);

    if (seen[hg][wg]) c("Yes")
    else c("No")

    return 0;
}
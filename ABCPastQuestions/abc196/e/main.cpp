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

ll filter(ll x, vector<ll> &a, vector<ll> &t) {
    REP (i, a.size()) {
        if (t[i] == 1) x += a[i];
        else if (t[i] == 2) x = max(a[i], x);
        else x = min(a[i], x);
    }
    return x;
}

void solve(long long N, std::vector<long long> a, std::vector<long long> t, long long Q, std::vector<long long> x){
    
    // 答えの最大値を二分探索で求める
    ll mx_o = filter(INF64, a, t);
    ll ng = -INF64, ok = INF64;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
    
        if (filter(mid, a, t) == mx_o) ok = mid;
        else ng = mid;
    }
    ll mx = ok;

    // 答えの最小値を二分探索で求める
    ll mn_o = filter(-INF64, a, t);
    ng = INF64, ok = -INF64;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
    
        if (filter(mid, a, t) == mn_o) ok = mid;
        else ng = mid;
    }
    ll mn = ok;

    // cout << mx << " " << mx_o << " " << mn << " " << mn_o << endl;

    ll X = 0;
    REP (i, N) if (t[i] == 1) X += a[i];

    REP (i, Q) {
        if (x[i] >= mx) cout << mx_o << endl;
        else if (x[i] <= mn) cout << mn_o << endl;
        else cout << X + x[i] << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    std::vector<long long> t(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&t[i]);
    }
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> x(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&x[i]);
    }
    solve(N, std::move(a), std::move(t), Q, std::move(x));
    return 0;
}

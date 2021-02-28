#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
using Graph = vector<vector<ll>>;
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


void solve(long long W, long long H, long long N, std::vector<long long> x, std::vector<long long> y, std::vector<long long> a){
    ll x_min = W;
    ll x_max = 0;
    ll y_min = H;
    ll y_max = 0;
    REP (i, N) {
        if (a[i] == 1) {
            chmax(x_max, x[i]);
        } else if (a[i] == 2) {
            chmin(x_min, x[i]);
        } else if (a[i] == 3) {
            chmax(y_max, y[i]);
        } else {
            chmin(y_min, y[i]);
        }
    }
    ll X = max(0LL, x_min - x_max);
    ll Y = max(0LL, y_min - y_max);
    ll ans = X * Y;
    c(ans)
}

int main(){
    long long W;
    scanf("%lld",&W);
    long long H;
    scanf("%lld",&H);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        scanf("%lld",&a[i]);
    }
    solve(W, H, N, std::move(x), std::move(y), std::move(a));
    return 0;
}

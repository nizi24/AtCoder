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
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

bool st(pair<ll, ll> first, pair<ll, ll> second) {
    if (first.first < second.first) return true;
    else if (first.first == second.first && first.second > second.second) return true;
    return false;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    REP (i, N) cin >> x[i] >> y[i];

    vector<pair<ll, ll>> xy;
    REP (i, N) xy.push_back({x[i], y[i]});
    sort(all(xy));

    map<pair<ll, ll>, ll> cnt;
    REP (i, N) {
        for (int j = i + 1; j < N; j++) {
            cnt[{xy[j].first - xy[i].first, xy[j].second - xy[i].second}]++;
        }
    }

    ll max = 0;
    for (auto c : cnt) {
        chmax(max, c.second);
    }

    c(N - max)

    return 0;
}
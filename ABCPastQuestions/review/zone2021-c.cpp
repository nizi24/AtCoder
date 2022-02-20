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
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

ll N;
vector<vector<ll>> s;

bool check(ll S) {
    ll x = 1 << 5;
    vector<ll> v(x, 0);
    REP (i, N) {
        int cur = 0;
        REP (j, 5) {
            if (s[i][j] >= S) cur |= (1 << j);
        }
        v[cur] = 1;
    }

    REP (i, x) {
        if (!v[i]) continue;
        REP (j, x) {
            if (!v[j]) continue;
            REP (k, x) {
                if (!v[k]) continue;

                if ((i | j | k) == (x-1)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    s.resize(N, vector<ll>(5));
    REP (i, N) {
        cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3] >> s[i][4];
    }

    ll ng = INF64;
    ll ok = 0;
    
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
    
        if (check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}
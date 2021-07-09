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

int main() {
    int n;
    cin >> n;
    vector<ll> E(n);
    REP (i, n) cin >> E[i];

    for (int bit1 = 1; bit1 < (1<<n); bit1++) {
        vector<ll> F;
        ll a = 0;
        for (int i = 0; i < n; i++) {
            if (bit1 & (1 << i)) F.push_back(E[i]);
            else a += E[i];
        }

        ll sz = F.size();
        for (int bit2 = 1; bit2 < (1<<sz); bit2++) {
            ll b = 0, c = 0;
            for (int i = 0; i < sz; i++) {
                if (bit2 & (1 << i)) b += F[i];
                else c += F[i];
            }

            if (a == b && b == c) {
                c("Yes")
                return 0;
            }
        }
    }

    c("No")
}
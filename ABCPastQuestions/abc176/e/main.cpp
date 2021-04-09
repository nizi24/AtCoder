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


void solve(long long H, long long W, long long M, std::vector<long long> h, std::vector<long long> w){
    vector<ll> ver(W, 0);
    vector<ll> ho(H, 0);

    set<pair<ll, ll>> st;
    REP (i, M) {
        h[i]--;
        w[i]--;
        ver[w[i]]++;
        ho[h[i]]++;
        st.insert({h[i], w[i]});
    }

    ll v_mx = 0;
    ll v_i = 0;
    ll ok = 0;
    REP (i, W) {
        if (chmax(v_mx, ver[i])) {
            v_i = i;
            ok = 1;
        } else if (v_mx == ver[i]) ok = 0;
    }

    ll ans = 0;
    if (!ok) {
        ll h_mx = 0;
        ll h_i = 0;
        REP (i, H) {
            if (chmax(h_mx, ho[i])) h_i = i;
        }

        REP (i, W) {
            if (st.count({h_i, i})) chmax(ans, h_mx + ver[i] - 1);
            else chmax(ans, h_mx + ver[i]);
        }
    } else {
        REP (i, H) {
            if (st.count({i, v_i})) chmax(ans, v_mx + ho[i] - 1);
            else chmax(ans, v_mx + ho[i]);
        }
    }

    c(ans)
    
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> h(M);
    std::vector<long long> w(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&h[i]);
        scanf("%lld",&w[i]);
    }
    solve(H, W, M, std::move(h), std::move(w));
    return 0;
}

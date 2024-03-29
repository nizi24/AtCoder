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

bool isOK(ll mid, ll N, ll K, vector<ll> &A, vector<ll> &F) {
    REP (i, N) {
        // 修行により減らさないといけない成績
        ll remain = max(0LL, A[i] * F[i] - mid);
        // 修行した数を減らす
        K -= myceil(remain, F[i]);
        // 修行回数が足りなければNG
        if (K < 0) return false;
    }
    return true;
}

void solve(long long N, long long K, std::vector<long long> A, std::vector<long long> F){
    sort(rall(A));
    sort(all(F));

    ll ng = -1;
    ll ok = INF64;
    
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
    
        if (isOK(mid, N, K, A, F)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> F(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&F[i]);
    }
    solve(N, K, std::move(A), std::move(F));
    return 0;
}

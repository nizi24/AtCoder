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


void solve(long long n, std::vector<long long> v){
    map<ll, ll> mp1;
    map<ll, ll> mp2;
    for (int i = 0; i < n; i += 2) mp1[v[i]]++;
    for (int i = 1; i < n; i += 2) mp2[v[i]]++;
    ll mx1 = 0;
    ll num1 = 0;
    ll mx2 = 0;
    ll num2 = 0;
    for (auto m : mp1) if (chmax(mx1, m.second)) num1 = m.first;
    for (auto m : mp2) if (chmax(mx2, m.second)) num2 = m.first;
    if (num1 != num2) {
        c((n - mx1 - mx2))
    } else {
        ll sec_mx1 = 0;
        ll sec_mx2 = 0;
        ll sec1 = 0;
        ll sec2 = 0;
        for (auto m : mp1) if (m.first != num1 && chmax(sec_mx1, m.second)) sec1 = m.first;
        for (auto m : mp2) if (m.first != num2 && chmax(sec_mx2, m.second)) sec2 = m.first;
        ll mx = max(mx1 + sec_mx2, sec_mx1 + mx2);
        c(n - mx)
    }
}

int main(){
    long long n;
    scanf("%lld",&n);
    std::vector<long long> v(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&v[i]);
    }
    solve(n, std::move(v));
    return 0;
}

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


void solve(long long Q, std::vector<long long> l, std::vector<long long> r){
    vector<ll> prime(100010, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i <= 100010; i++) {
        if (!prime[i]) continue;
        for (int j = i * 2; j <= 100010; j += i) prime[j] = 0;
    }

    vector<ll> cnt(100010, 0);
    for (int i = 1; i <= 100000; i++) {
        if (prime[i] && prime[(i + 1) / 2]) {
            cnt[i]++;
        }
        cnt[i] += cnt[i - 1];
    }

    REP (i, Q) {
        c(cnt[r[i]] - cnt[l[i] - 1])
    }
}

int main(){
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> l(Q);
    std::vector<long long> r(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&l[i]);
        scanf("%lld",&r[i]);
    }
    solve(Q, std::move(l), std::move(r));
    return 0;
}

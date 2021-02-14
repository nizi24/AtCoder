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


void solve(long long N, long long M, std::vector<long long> P, std::vector<long long> Y){
    map<ll, set<pair<ll, ll>>> mp;
    REP (i, M) mp[P[i]].insert(make_pair(Y[i], i));
    vector<pair<ll, ll>> vec(M);
    for (auto m: mp) {
        ll cnt = 0;
        for (auto v : m.second) {
            cnt++;
            vec[v.second] = make_pair(m.first, cnt);
        }
    }
    REP (i, M) {
        printf("%06d", vec[i].first);
        printf("%06d\n", vec[i].second);
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> P(M);
    std::vector<long long> Y(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&P[i]);
        scanf("%lld",&Y[i]);
    }
    solve(N, M, std::move(P), std::move(Y));
    return 0;
}

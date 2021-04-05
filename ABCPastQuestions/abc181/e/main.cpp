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


void solve(long long N, long long M, std::vector<long long> H, std::vector<long long> W){
    ALL(sort, H);
    ALL(sort, W);

    vector<ll> sum(N, 0);
    
    for (int i = 1; i < N; i += 2) {
        sum[0] += abs(H[i + 1] - H[i]);
    }

    ll mn = INF64;
    REP (i, N) {
        int lower_iter = lower_bound(all(W), H[i]) - W.begin();
        
        chmin(mn, sum[i] + abs(H[i] - W[lower_iter]));

        if (lower_iter) chmin(mn, sum[i] + abs(H[i] - W[lower_iter - 1]));

        if (i != N - 1) {
            sum[i + 1] = sum[i];

            if (i % 2 == 0) {
                sum[i + 1] -= abs(H[i + 2] - H[i + 1]);
                sum[i + 1] += abs(H[i + 2] - H[i]);
            } else {
                sum[i + 1] -= abs(H[i + 1] - H[i - 1]);
                sum[i + 1] += abs(H[i] - H[i - 1]);
            }
        }
    }

    c(mn)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    std::vector<long long> W(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&W[i]);
    }
    solve(N, M, std::move(H), std::move(W));
    return 0;
}

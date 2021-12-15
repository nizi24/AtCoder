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
#define REP(i, n) for (ll i = 0; i < n; i++)
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


void solve(long long N, long long K, std::vector<long long> A) {
    vector<ll> b(40, 0);
    REP (i, N) {
        REP (j, 40) {
            if ((1LL << j) & A[i]) b[j]++;
        }
    }
    

    vector<vector<ll>> dp(41, vector<ll>(2, 0));
    bool first_one = 0;
    for (int i = 39; i >= 0; i--) {
        ll zero = b[i] * (1LL << i);
        ll one =  (N-b[i]) * (1LL << i);

        if (first_one) {
            chmax(dp[i][1], max(dp[i+1][1] + zero, dp[i+1][1] + one));
        }

        if ((1LL << i) & K) {
            dp[i][0] = dp[i+1][0] + one;
            chmax(dp[i][1], dp[i+1][0] + zero);
            first_one = 1;
        } else {
            dp[i][0] = dp[i+1][0] + zero;
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;
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
    solve(N, K, std::move(A));
    return 0;
}

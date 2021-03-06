#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
using Graph = vector<vector<ll>>;
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

const long long MOD = 2;

void solve(long long N, long long P, std::vector<long long> A){
    ll odd = 0;
    ll even = 0;
    REP (i, N) {
        if (A[i] % 2 == 0) even++;
        else odd++;
    }
    ll ans = 0;
    ll odd_cnt = 0;
    if (P == 0) {
        ans += pow(2, even);
        odd_cnt = 2;
    } else {
        odd_cnt = 1;
    }
    while (odd_cnt <= N) {
        __int128_t c = 1;
        __int128_t C = 1;
        REP (i, odd_cnt) {
            c *= odd - i;
            C *= odd_cnt - i;
            if (c % C == 0) {
                c /= C;
                C = 1;
            }
        }
        ans += c / C * pow(2, even);
        odd_cnt += 2;
    }
    c(ans)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long P;
    scanf("%lld",&P);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, P, std::move(A));
    return 0;
}

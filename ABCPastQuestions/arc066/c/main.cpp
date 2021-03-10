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
#define EPS14  1.0E-14
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

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A){
    ll md2 = N % 2;
    map<ll, ll> mp;
    REP (i, N) mp[A[i]]++;
    if (!md2) {
        if (mp[0]) {
            c(0)
            return;
        }
    } else {
        if (mp[0] != 1) {
            c(0)
            return;
        }
    }
    ll cnt = 0;
    for (auto m : mp) {
        if (m.first) {
            if (m.first % 2 == 0) {
                if (!md2) {
                    c(0)
                    return;
                }
            } else {
                if (md2) {
                    c(0)
                    return;
                }
            }
            if (m.second != 2) {
                c(0)
                return;
            }
            cnt++;
        }
    }
    ll ans = 1;
    REP (i, cnt) {
        ans *= 2;
        ans %= MOD;
    }
    c(ans)
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

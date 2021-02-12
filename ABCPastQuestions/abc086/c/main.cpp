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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> t, std::vector<long long> x, std::vector<long long> y){
    vector<long long> def(N);
    REP (i, N) {
        if (i == 0) def[i] = abs(x[i] - 0) + abs(y[i] - 0);
        else def[i] = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        // c(def[i])
    }
    string ans = YES;
    REP (i, N) {
        if (i == 0) {
            if ((t[i] % 2 == 0 && def[i] % 2 == 0) || (t[i] % 2 != 0 && def[i] % 2 != 0)) {
                if (t[i] < def[i]) {
                    ans = NO;
                    break;
                }
            } else {
                ans = NO;
                break;
            }
        } else {
            ll T = t[i] - t[i - 1];
            if ((T % 2 == 0 && def[i] % 2 == 0) || (T % 2 != 0 && def[i] % 2 != 0)) {
                if (T < def[i]) {
                    ans = NO;
                    break;
                }
            } else {
                ans = NO;
                break;
            }
        }
    }
    c(ans)
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> t(N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(t), std::move(x), std::move(y));
    return 0;
}

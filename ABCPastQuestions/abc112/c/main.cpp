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


void solve(long long N, std::vector<long long> x, std::vector<long long> y, std::vector<long long> h){

    REP (i, 101) {
        REP (j, 101) {
            vector<ll> H(N, 0);
            ll prev = 0;

            REP (k, N) {
                H[k] = abs(x[k] - i) + abs(y[k] - j) + h[k];
                if (h[k] != 0) prev = H[k];
            }

            bool ok = 1;
            REP (k, N) {
                if (h[k] == 0) {
                    if (prev > H[k]) {
                        ok = 0;
                        break;
                    }
                } else {
                    if (prev != H[k]) {
                        ok = 0;
                        break;
                    }
                }
            }

            if (ok) {
                c(i << " " << j << " " << prev)
                return;
            }
        }
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> h(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        scanf("%lld",&h[i]);
    }
    solve(N, std::move(x), std::move(y), std::move(h));
    return 0;
}

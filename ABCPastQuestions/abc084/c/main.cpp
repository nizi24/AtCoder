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


void solve(long long N, std::vector<long long> C, std::vector<long long> S, std::vector<long long> F){
    REP (i, N) {
        ll cur = 0;
        for (int j = i; j < N - 1; j++) {
            if (S[j] > cur) cur += S[j] - cur;
            else {
                if ((cur - S[j]) % F[j] != 0) {
                    cur += F[j] - (cur - S[j]) % F[j];
                }
            }
            cur += C[j];
        }
        c(cur)
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> C(N-1);
    std::vector<long long> S(N-1);
    std::vector<long long> F(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&C[i]);
        scanf("%lld",&S[i]);
        scanf("%lld",&F[i]);
    }
    solve(N, std::move(C), std::move(S), std::move(F));
    return 0;
}

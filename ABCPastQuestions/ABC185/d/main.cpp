#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define MOD 1000000007
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



int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    REP (i, M) cin >> A[i];
    ALL(sort, A);
    vector<ll> section;
    ll min = INF64;
    REP (i, M) {
        ll sec = 0;
        if (i == 0) sec = A[i] - 1;
        else sec = A[i] - A[i - 1] - 1;
        if (sec != 0) {
            section.push_back(sec);
            chmin(min, sec);
        }
        if (i == M - 1) {
            sec = N - A[i];
            if (sec != 0) {
                section.push_back(sec);
                chmin(min, sec);
            }
        }
    }
    ll ans = 0;
    REP (i, section.size()) {
        ans += myceil(section[i], min);
    }

    if (M) c(ans)
    else c(1)
    return 0;
}

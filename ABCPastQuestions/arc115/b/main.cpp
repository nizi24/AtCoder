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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<std::vector<long long>> C){
    vector<vector<ll>> ans(2, vector<ll>(N, 0));

    ans[0][0] = C[0][0];
    ans[1][0] = 0;

    for (int i = 1; i < N; i++) {
        ans[0][i] = C[i][0] - 0;
    }

    ll min = 0;
    for (int i = 1; i < N; i++) {
        ans[1][i] = C[0][i] - C[0][0];

        chmin(min, ans[1][i]);
    }

    if (min < 0) {
        for (int i = 0; i < N; i++) {
            ans[0][i] -= -min;
        }

        for (int i = 0; i < N; i++) {
            ans[1][i] += -min;
        }
    }
    
    REP (i, N) {
        REP (j, N) {
            if (ans[0][i] + ans[1][j] != C[i][j]) {
                c(NO)
                return;
            }
        }
    }

    c(YES)

    REP (i, N) {
        cout << ans[0][i] << " ";
    }
    cout << endl;

    REP (i, N) {
        cout << ans[1][i] << " ";
    }
    cout << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::vector<long long>> C(N, std::vector<long long>(N));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%lld",&C[i][j]);
        }
    }
    solve(N, std::move(C));
    return 0;
}

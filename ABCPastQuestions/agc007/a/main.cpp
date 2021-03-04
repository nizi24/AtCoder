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

const string YES = "Possible";
const string NO = "Impossible";


int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    REP (i, H) cin >> A[i];
    ll cnt = 0;
    REP (i, H) REP (j, W) if (A[i][j] == '#') cnt++;
    ll x = 0;
    ll y = 0;
    ll cur = 1;
    while (true) {
        bool ok = 0;
        if (x < W - 1) {
            if (A[y][x + 1] == '#') {
                x++;
                ok = 1;
                cur++;
            }
        }
        if (y < H - 1) {
            if (A[y + 1][x] == '#') {
                y++;
                ok = 1;
                cur++;
            }
        }
        if (!ok) break;
    }
    if (cur == cnt) c(YES)
    else c(NO)
    return 0;
}

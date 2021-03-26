#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
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
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}


void solve(long long A, long long B) {
    vector<ll> power(41);
    REP (i, 41) power[i] = pw(2, i);

    vector<ll> cnt(41, 0);
    ll prev = 0;
    ll prev_b = 0;
    for (ll i = 40; i >= 0; i--) {
        ll bit = (1LL << i);
        ll a = max(0LL, (A - 1) / power[i] - (((A - 1) & bit) > 0)) - prev;
        ll b = max(0LL, B / power[i] - ((B & bit) > 0)) - prev_b;

        prev = (A - 1) / power[i];
        prev_b = B / power[i];
        a *= power[i]; b *= power[i];

        if ((A - 1) & bit) {
            a++;    
            REP (j, i) {
                ll bit_j = (1LL << j);
                if ((A - 1) & bit_j) a += power[j];
            }
        }
        if (B & bit) {
            b++;
            REP (j, i) {
                ll bit_j = (1LL << j);
                if (B & bit_j) b += power[j];
            }
        }

        if (A == 0) {
            prev = 0;
            a = 0;
        }
        if (B == 0) {
            prev_b = 0;
            b = 0;
        }
        
        cnt[i] = b - a;
    }

    ll ans = 0;
    REP (i, 41) {
        if (cnt[i] % 2 != 0) ans += pw(2, i);
    }

    // ll test = A;
    // cout << bitset<8>(A) << endl;
    // for (int i = A + 1; i <= B; i++) {
    //     test ^= i;
    //     cout << bitset<8>(i) << endl;
    // }
    // c(test)

    c(ans)
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}

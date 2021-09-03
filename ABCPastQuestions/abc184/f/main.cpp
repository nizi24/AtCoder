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
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}


void solve(long long N, long long T, std::vector<long long> A){
    // N/2を繰り上げたもの
    int n = myceil(N, 2LL);

    // sm1: 前半、sm2: 後半
    vector<ll> sm1, sm2;
    // bit全探索で問題の選び方を全探索
    // Nが奇数の可能性があるため、if文を使って結果を調整している
    for (int bit = 0; bit < (1<<n); bit++) {
        ll cur1 = 0;
        ll cur2 = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) {
                if (N/2 == n || i != n-1) cur1 += A[i];
                cur2 += A[N/2+i];
            }
        }

        if (N/2 == n || bit <= (1<<(n-1))) sm1.push_back(cur1);
        sm2.push_back(cur2);
    }

    sort(all(sm2)); // sm2を昇順ソート

    ll mx = 0;
    REP (i, sm1.size()) {
        // 二分探索でT-sm[i]以下で最大のsm2の要素を探す
        auto iter = upper_bound(all(sm2), T-sm1[i]) - 1;
        ll cur = sm1[i]+*iter;
        if (cur <= T) chmax(mx, cur);
    }

    cout << mx << endl; // 出力
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long T;
    scanf("%lld",&T);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, T, std::move(A));
    return 0;
}

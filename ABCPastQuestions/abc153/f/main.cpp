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


void solve(long long N, long long D, long long A, std::vector<long long> X, std::vector<long long> H){
    multiset<pair<ll, ll>> st;
    REP (i, N) st.insert({X[i], H[i]});

    // zahyo: 現在の座標
    // damege: 蓄積ダメージ
    // ans: 答え
    ll zahyo = 0, damage = 0, ans = 0;
    auto iter = st.begin(); // イテレータ
    // first: 爆弾の爆発範囲端の座標, second: 爆発ダメージ
    // 蓄積ダメージの計算に使用
    map<ll, ll> mp;
    while (iter != st.end()) {
        // st.second()
        // 爆弾の爆発範囲端の場合: -1, それ以外の場合モンスターのH[i]
        if ((*iter).second != -1) {
            // 現在の対象モンスターが射程のギリギリになるように爆弾を使用
            zahyo = (*iter).first + D*2;
            // 爆弾の使用回数
            ll cnt = max(0LL, myceil((*iter).second-damage, A));

            ans += cnt;
            damage += A * cnt; // 蓄積ダメージを追加
            mp[zahyo+1] = A * cnt;
            // first: 爆発範囲の範囲外の座標
            st.insert({zahyo+1, -1});
        } else {
            // 蓄積ダメージを減らす
            damage -= mp[(*iter).first];
        }
        iter++;
    }

    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long D;
    scanf("%lld",&D);
    long long A;
    scanf("%lld",&A);
    std::vector<long long> X(N);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&H[i]);
    }
    solve(N, D, A, std::move(X), std::move(H));
    return 0;
}

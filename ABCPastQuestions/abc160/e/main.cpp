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


void solve(long long X, long long Y, long long A, long long B, long long C, std::vector<long long> p, std::vector<long long> q, std::vector<long long> r){
    sort(rall(p));
    sort(rall(q));
    sort(rall(r));
    priority_queue<ll, vector<ll>, greater<ll>> que;
    REP (i, X) que.push(p[i]);
    REP (i, Y) que.push(q[i]);

    ll ans = 0;    
    ll cnt = 0;
    REP (i, X + Y) {
        if (que.top() < r[cnt]) {
            ans += r[cnt];
            cnt++;
        } else {
            ans += que.top();
        }
        que.pop();
    }

    c(ans)
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    std::vector<long long> p(A);
    for(int i = 0 ; i < A ; i++){
        scanf("%lld",&p[i]);
    }
    std::vector<long long> q(B);
    for(int i = 0 ; i < B ; i++){
        scanf("%lld",&q[i]);
    }
    std::vector<long long> r(C);
    for(int i = 0 ; i < C ; i++){
        scanf("%lld",&r[i]);
    }
    solve(X, Y, A, B, C, std::move(p), std::move(q), std::move(r));
    return 0;
}

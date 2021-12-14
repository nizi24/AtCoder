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
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}


void solve(long long L){
    if (L == 2) {
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 2 << " " << 0 << endl;
        cout << 1 << " " << 2 << " " << 1 << endl;
        return;
    }

    L--;

    ll cnt = 0, mask = 0;
    REP (i, 21) {
        mask += pw(2, i);
        if (pw(2, i) > L) {
            cnt = i;
            break;
        }
    }

    vector<vector<pair<ll, ll>>> G(cnt);

    // 本線の構築
    REP (i, cnt-1) {
        G[cnt-i-2].push_back({cnt-i, pw(2, i)});
        G[cnt-i-2].push_back({cnt-i, 0});
    }


    // 迂回路の構築
    bool first_one = 0;
    REP (i, cnt-1) {
        mask -= pw(2, i);
        if ((1 << i) & L) {
            G[0].push_back({cnt-i, L & mask});
        }
    }
    G[0].push_back({cnt, L});

    // 辺の数を数える
    int edge = 0;
    REP (i, cnt) edge += G[i].size();

    cout << cnt << " " << edge << endl;
    REP (i, cnt) {
        for (auto p : G[i]) cout << i+1 << " " << p.first << " " << p.second << endl;
    }
}

int main(){
    long long L;
    scanf("%lld",&L);
    solve(L);
    return 0;
}

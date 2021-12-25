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

bool pairwise(vector<ll> A) {
    vector<int> cnt(1000001, 0);
    REP (i, A.size()) cnt[A[i]]++;

    vector<bool> seen(1000001, 0);
    for (int i = 2; i <= 1000000; i++) {
        if (seen[i]) continue;

        int c = 0;
        for (int j = i; j <= 1000000; j += i) {
            seen[j] = true;
            c += cnt[j];
            if (c >= 2) return false;
        }
    }

    return true;
}

bool setwise(vector<ll> A) {
    ll GCD = A[0];
    REP (i, A.size()) GCD = __gcd(GCD, A[i]);
    
    return GCD < 2;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP (i, N) cin >> A[i];

    bool p = pairwise(A), s = setwise(A);
    if (p) cout << "pairwise coprime" << endl;
    else if (s) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
}
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

void rec(int n, int t, vector<string> &res, string cur, int bit) {
    if (bit == (1 << n) - 1) {
        res.push_back(cur);
        return;
    }
    // c(bit)


    vector<pair<ll, ll>> bit_search;
    for (int i = 0; i < n; i++) {
        if (!(bit & (1 << i))) {
            bit_search.push_back({(1 << i), n - i - 1});
        }
    }

    ll N = bit_search.size();
    ll next = bit + bit_search[N - 1].first;
    string C = cur;
    C[bit_search[N - 1].second] = 'a' + t;


    for (int b = 0; b < (1 << N - 1); b++) {
        string c = C;
        int next_bit = next;

        for (int i = 0; i < N - 1; i++) {
            if (b & (1 << i)) {
                c[bit_search[i].second] = 'a' + t;
                next_bit += bit_search[i].first;
            }
        }

        rec(n, t + 1, res, c, next_bit);
    }
}

int main() {
    ll N;
    cin >> N;

    vector<string> res;
    string cur;
    REP (i, N) cur.push_back(' ');
    rec(N, 0, res, cur, 0);

    sort(all(res));

    REP (i, res.size()) {
        c(res[i])
    }


    return 0;
}
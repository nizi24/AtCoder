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


void solve(std::string ABCD){
    ll a = ABCD[0] - '0';
    ll b = ABCD[1] - '0';
    ll c = ABCD[2] - '0';
    ll d = ABCD[3] - '0';
    REP (i, 2) {
        ll res = 0;
        if (i == 0) res += a + b;
        else res += a - b;
        REP (j, 2) {
            ll jres = res;
            if (j == 0) jres += c;
            else jres -= c;
            REP (k, 2) {
                ll kres = jres;
                if (k == 0) kres += d;
                else kres -= d;
                if (kres == 7) {
                    cout << a;
                    cout << (i == 0 ? "+" : "-") << b;
                    cout << (j == 0 ? "+" : "-") << c;
                    cout << (k == 0 ? "+" : "-") << d;
                    cout << "=7";
                    cout << endl;
                    return;
                }
            }
        }
    }
}

int main(){
    std::string ABCD;
    std::cin >> ABCD;
    solve(ABCD);
    return 0;
}

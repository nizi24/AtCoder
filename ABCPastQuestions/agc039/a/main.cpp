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


void solve(std::string S, long long K){
    vector<ll> roop(4, 0);
    string ss = S + S + S + S;
    ll k = 0;
    ll cur = 0;
    REP (i, ss.size()) {
        if (S.size() * (k + 1) - 1 == i) {
            roop[k] = cur;
            k++;
        }
        ll j = i;
        while (j < ss.size() - 1 && ss[i] == ss[j + 1]) {
            j++;
            if (S.size() * (k + 1) - 1 == j) {
                roop[k] = (j - i + 1) / 2 + cur;
                k++;
            }
        }
        cur +=  (j - i + 1) / 2;
        i = j;
    }
    if (roop[1] - roop[0] == roop[2] - roop[1]) {
        c((roop[1] - roop[0]) * (K - 1) + roop[0])
    } else {
        c(K / 2 * roop[1] + (K % 2 == 0 ? 0 : roop[0]))
    }
}

int main(){
    std::string S;
    std::cin >> S;
    long long K;
    scanf("%lld",&K);
    solve(S, K);
    return 0;
}

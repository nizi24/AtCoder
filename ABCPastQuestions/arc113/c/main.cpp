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


void solve(std::string S){
    ll ans = 0;
    ll s_size = S.size();
    map<char, ll> char_count;
    pair<char, ll> pre = make_pair(' ', s_size);
    for (int i = s_size - 1; i > 1; i--) {
        char_count[S[i]]++;
        if (S[i] != S[i - 1] && S[i - 1] == S[i - 2]) {
            if (pre.first != S[i - 1]) {
                ans += s_size - i;
            } else {
                ans += pre.second - i;
            }
            ans -= char_count[S[i - 1]];
            pre.first = S[i - 1];
            pre.second = i;
            char_count = map<char, ll>();
        }
    }
    c(ans)
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

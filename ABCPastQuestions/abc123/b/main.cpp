#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long A, long long B, long long C, long long D, long long E){
    int ans = 0;
    ans += myceil(A, 10LL) + myceil(B, 10LL) + myceil(C, 10LL) + myceil(D, 10LL) + myceil(E, 10LL);
    ans *= 10;
    int mn = min((A-1) % 10, min((B-1) % 10, min((C-1) % 10, min((D-1)% 10, (E-1) % 10))));
    if (mn != 9) ans -= 10 - (mn + 1);
    c(ans)
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long D;
    scanf("%lld",&D);
    long long E;
    scanf("%lld",&E);
    solve(A, B, C, D, E);
    return 0;
}

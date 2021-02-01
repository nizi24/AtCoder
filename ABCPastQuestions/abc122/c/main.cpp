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


void solve(long long N, long long Q, std::string S, std::vector<long long> l, std::vector<long long> r){
    int ac = 0;
    vector<int> AC(N);
    REP (i, N) {
        if (i != 0) if (S[i - 1] == 'A' && S[i] == 'C') ac++;
        AC[i] = ac;
    }
    REP (i, Q) {
        ll ans = AC[r[i]-1] - AC[l[i]-1];
        c(ans)
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::string S;
    std::cin >> S;
    std::vector<long long> l(Q);
    std::vector<long long> r(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&l[i]);
        scanf("%lld",&r[i]);
    }
    solve(N, Q, S, std::move(l), std::move(r));
    return 0;
}

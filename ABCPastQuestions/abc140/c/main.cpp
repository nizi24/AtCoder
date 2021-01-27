#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long N, std::vector<long long> B){
    vector<ll> A(N+10, 0);
    A[0] = B[0];
    REP (i, N - 1) {
        A[i + 1] = B[i];
        if (A[i] > B[i]) A[i] = B[i];
    }
    ll ans = 0;
    REP (i, N) ans += A[i];
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> B(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(B));
    return 0;
}

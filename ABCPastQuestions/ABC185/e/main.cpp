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



int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    REP (i, N) cin >> A[i];
    REP (i, M) cin >> B[i];

    vector<vector<ll>> dp(N+2, vector<ll>(M+2, INF64));
    dp[0][0] = 0;
    
    REP (i, N+1) {
        REP (j, M+1) {
            // A の末尾を削除
            if (i > 0) chmin(dp[i][j], dp[i-1][j] + 1);

            // B の末尾を削除
            if (j > 0) chmin(dp[i][j], dp[i][j-1] + 1);

            // A の末尾と B の末尾を対応させる
            if (i > 0 && j > 0) {
                if (A[i-1] == B[j-1]) chmin(dp[i][j], dp[i-1][j-1]);
                else chmin(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }

    c(dp[N][M])

    return 0;
}

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


void solve(long long N, long long M, std::vector<long long> A) {
    vector<ll> match = {2,5,5,4,5,6,3,7,6};
    vector<vector<ll>> dp(N+1, vector<ll>(M, -INF));

    REP (i, M) {
        A[i]--;
        if (N - match[A[i]] >= 0) {
            dp[N - match[A[i]]][i] = 1;
        }
    }

    for (int i = N; i >= 0; i--) {
        REP (j, M) {
            REP (k, M) {
                if (i - match[A[j]] >= 0) {
                    chmax(dp[i - match[A[j]]][j], dp[i][k] + 1);
                }
            }
        }
    }

    ll mx = -1, mx_keta = 0;
    REP (i, M) {
        if (chmax(mx_keta, dp[0][i])) mx = A[i];
        else if (mx_keta == dp[0][i]) chmax(mx, A[i]);
    }

    string ans = to_string(mx+1);
    ll cur = match[mx];
    mx_keta--;

    while (cur < N) {
        mx = -1;
        REP (i, M) {
            if (mx_keta == dp[cur][i]) {
                chmax(mx, A[i]);
            }
        }
        ans.push_back(mx+1 + '0');
        cur += match[mx];
        mx_keta--;
    }

    cout << ans << endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, M, std::move(A));
    return 0;
}

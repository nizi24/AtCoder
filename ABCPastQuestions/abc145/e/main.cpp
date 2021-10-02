#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long N, long long T, std::vector<long long> A, std::vector<long long> B){
    vector<pair<ll, ll>> vec;
    REP (i, N) {
        vec.push_back({A[i], B[i]});
    }
    // 昇順に並べておく
    ALL(sort, vec);

    // DPテーブル
    vector<vector<ll>> dp(N+1, vector<ll>(T+1, 0));

    REP (i, N) {
        REP (j, T) {
            // i番目の料理を食べる場合
            chmax(dp[i + 1][min(T, j + vec[i].first)], dp[i][j] + vec[i].second);
            // i番目の料理を食べない場合
            chmax(dp[i + 1][j], dp[i][j]);
        }
        // これを忘れない
        chmax(dp[i + 1][T], dp[i][T]);
    }

    // 集計して最大値を探す
    ll ans = 0;
    REP (i, T+1) chmax(ans, dp[N][i]);
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long T;
    scanf("%lld",&T);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, T, std::move(A), std::move(B));
    return 0;
}

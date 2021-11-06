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

struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

bool update(pair<ll, ll> &a, pair<ll, ll> b) {
    if (a.first > b.first) {
        a = b;
        return true;
    } else if (a.first == b.first) {
        if (a.second < b.second) {
            a = b;
            return true;
        }
        return false;
    }
    return false;
}

void solve(long long N, long long M, long long L, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C, long long Q, std::vector<long long> s, std::vector<long long> t){
    Graph G(N);
    REP (i, M) {
        if (C[i] <= L) {
            G[A[i]-1].push_back({B[i]-1, C[i]});
            G[B[i]-1].push_back({A[i]-1, C[i]});
        }
    }

    vector<vector<ll>> dp(N, vector<ll>(N, INT64_MAX / 2));
    REP (i, N) dp[i][i] = 0;

    REP (i, M) {
        dp[A[i]-1][B[i]-1] = C[i];
        dp[B[i]-1][A[i]-1] = C[i];
    }

    REP (i, N) {
        REP (j, N) {
            REP (k, N) {
                chmin(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }

    REP (i, N) {
        REP (j, N) {
            if (i != j) {
                if (dp[i][j] <= L) dp[i][j] = 1;
                else dp[i][j] = INF;
            }
        }
    }

    REP (i, N) {
        REP (j, N) {
            REP (k, N) {
                chmin(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }

    REP (i, Q) {
        cout << (dp[s[i]-1][t[i]-1] >= INF ? -1 : dp[s[i]-1][t[i]-1]-1) << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long L;
    scanf("%lld",&L);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    std::vector<long long> C(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
    }
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> s(Q);
    std::vector<long long> t(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&s[i]);
        scanf("%lld",&t[i]);
    }
    solve(N, M, L, std::move(A), std::move(B), std::move(C), Q, std::move(s), std::move(t));
    return 0;
}

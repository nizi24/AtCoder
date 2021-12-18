#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long N, long long K){
    ll C = (N-1) * (N-2) / 2;
    if (K > C) {
        cout << -1 << endl;
        return;
    }

    ll M = N-1;
    vector<vector<ll>> G(N);

    // スターグラフ構築
    REP (i, N-1) G[0].push_back(i + 1);

    // 辺を追加
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (K == C) break;
            G[i].push_back(j);
            K++; M++;
        }
    }

    cout << M << endl;
    REP (i, N) for (auto g : G[i]) cout << i+1 << " " << g+1 << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    solve(N, K);
    return 0;
}

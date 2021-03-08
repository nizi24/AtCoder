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


void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
    vector<pair<ll, ll>> vec;
    REP (i, N) {
        vec.push_back({A[i], 1});
    }
    REP (i, M) {
        vec.push_back({C[i], B[i]});
    }
    ALL(sort, vec);
    ALL(reverse, vec);
    ll ans = 0;
    ll cnt = 0;
    REP (i, vec.size()) {
        if (cnt + vec[i].second <= N) {
            ans += vec[i].first * vec[i].second;
            cnt += vec[i].second;
        } else {
            ans += vec[i].first * (N - cnt);
            cnt = N;
        }
        if (cnt >= N) break;
    }
    c(ans)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(M);
    std::vector<long long> C(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
    }
    solve(N, M, std::move(A), std::move(B), std::move(C));
    return 0;
}

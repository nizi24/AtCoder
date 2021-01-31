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


void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B, long long K, std::vector<long long> C, std::vector<long long> D){
    set<ll> st;
    ll mx = 0;
    for (int bit = 0; bit < (1 << K); bit++) {
        for (int i = 0; i < K; i++) {
            if (bit & (1 << i)) {
                st.insert(D[i]);
            } else st.insert(C[i]);
        }
        ll ans = 0;
        REP (i, M) if (st.count(A[i]) && st.count(B[i])) ans++;
        chmax(mx, ans);
        ans = 0;
        st.clear();
    }
    c(mx)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    long long K;
    scanf("%lld",&K);
    std::vector<long long> C(K);
    std::vector<long long> D(K);
    for(int i = 0 ; i < K ; i++){
        scanf("%lld",&C[i]);
        scanf("%lld",&D[i]);
    }
    solve(N, M, std::move(A), std::move(B), K, std::move(C), std::move(D));
    return 0;
}

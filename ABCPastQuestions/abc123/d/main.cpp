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
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long X, long long Y, long long Z, long long K, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
    vector<ll> AB;
    REP (i, X) {
        REP (j, Y) {
            AB.push_back(A[i] + B[j]);
        }
    }
    sort(rall(AB));

    vector<ll> ABC;
    REP (i, min(K, (ll)AB.size())) {
        REP (j, Z) {
            ABC.push_back(AB[i] + C[j]);
        }
    }
    sort(rall(ABC));

    REP (i, K) {
        cout << ABC[i] << endl;
    }
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    long long Z;
    scanf("%lld",&Z);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(X);
    for(int i = 0 ; i < X ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(Y);
    for(int i = 0 ; i < Y ; i++){
        scanf("%lld",&B[i]);
    }
    std::vector<long long> C(Z);
    for(int i = 0 ; i < Z ; i++){
        scanf("%lld",&C[i]);
    }
    solve(X, Y, Z, K, std::move(A), std::move(B), std::move(C));
    return 0;
}

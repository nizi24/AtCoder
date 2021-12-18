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


void solve(long long N, long long K, std::vector<long long> A){
    ll sum = 0;
    REP (i, N) sum += A[i];

    vector<long long> res;
    for (long long i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            res.push_back(i);
            if (sum/i != i) res.push_back(sum/i);
        }
    }

    ll ans = 1;
    REP (i, res.size()) {
        ll mod_sum = 0;
        vector<ll> mod_A;
        REP (j, N) {
            mod_sum += A[j] % res[i];
            mod_A.push_back(A[j] % res[i]);
        }
        
        ALL(sort, mod_A);
        int left = 0, right = N-1;
        ll m = 0, k = 0;
        while (left < right) {
            m += mod_A[left];
            k += mod_A[left];
            while (m + mod_A[right] >= res[i]) {
                m -= res[i] - mod_A[right];
                right--;
            }
            left++;
        }
        if (k <= K) chmax(ans, res[i]);
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}

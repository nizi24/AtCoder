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


void solve(long long N, long long K, std::vector<long long> V){
    ll ans = -INF * 10000LL;

    REP (i, N+1) {
        for (int j = N; j >= 0; j--) {
            int cnt = K - (i + (N-j));
            if (cnt < 0 || i > j) continue;

            multiset<ll> st;
            for (int l = 0; l < i; l++) st.insert(V[l]);
            for (int r = N-1; r >= j; r--) st.insert(V[r]);

            ll cur = 0;
            for (auto s : st) {
                if (s >= 0 || cnt <= 0) {
                    cur += s;
                } else cnt--;
            }

            chmax(ans, cur);
        }
    }

    c(ans)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> V(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&V[i]);
    }
    solve(N, K, std::move(V));
    return 0;
}

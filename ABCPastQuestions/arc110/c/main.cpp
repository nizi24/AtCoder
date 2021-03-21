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


void solve(long long N, std::vector<long long> P){
    ll pos = 0;
    ll neg = 0;
    set<ll> st;
    vector<tuple<ll, ll, ll>> vec; 
    for (int i = 1; i <= N; i++) {
        if (i > P[i]) {
            pos += i - P[i];
        } else if (i < P[i]) {
            neg += P[i] - i;
        } else {
            c(-1)
            return;
        }
        vec.push_back({P[i], i, P[i] - i});
    }

    if (pos == N - 1 && neg == N - 1) {
        sort(all(vec));

        REP (i, N) {
            if (get<2>(vec[i]) < 0) {
                for (int j = 1; j <= abs(get<2>(vec[i])); j++) {
                    if (!st.count(get<1>(vec[i]) - j)) {
                        c(get<1>(vec[i]) - j)
                        st.insert(get<1>(vec[i]) - j);
                    }
                }
            }
        }
    } else {
        c(-1)
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> P(N+1);
    for(int i = 1 ; i <= N ; i++){
        scanf("%lld",&P[i]);
    }
    solve(N, std::move(P));
    return 0;
}

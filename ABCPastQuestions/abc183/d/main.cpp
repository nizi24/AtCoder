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

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long W, std::vector<long long> S, std::vector<long long> T, std::vector<long long> P){
    vector<tuple<ll, ll, ll>> vec(N);
    REP (i, N) vec[i] = make_tuple(S[i], T[i], P[i]);
    ALL(sort, vec);
    ll max = 0;
    ll current_element = 0;
    ll sum = 0;
    map<ll, ll> current_elements;
    REP (i, 200001) {
        while (get<0>(vec[current_element]) == i) {
            sum += get<2>(vec[current_element]);
            current_elements[get<1>(vec[current_element])] += get<2>(vec[current_element]);
            current_element++;
        }
        if (current_elements.count(i)) {
            sum -= current_elements[i];
        }
        chmax(max, sum);
        if (max > W) {
            c(NO)
            return;
        }
        if (current_element == N - 1 && sum == 0) break;
    }
    c(YES)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long W;
    scanf("%lld",&W);
    std::vector<long long> S(N);
    std::vector<long long> T(N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&S[i]);
        scanf("%lld",&T[i]);
        scanf("%lld",&P[i]);
    }
    solve(N, W, std::move(S), std::move(T), std::move(P));
    return 0;
}

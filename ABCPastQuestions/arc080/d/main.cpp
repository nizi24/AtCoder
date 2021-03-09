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
#define EPS14  1.0E-14
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


void solve(long long H, long long W, long long N, std::vector<long long> a) {
    ll i = 0;
    vector<queue<ll>> mod0;
    vector<stack<ll>> mod1;
    bool mod = 0;
    queue<ll> que;
    stack<ll> st;
    REP (j, N) {
        REP (k, a[j]) {
            i++;
            if (mod) st.push(j + 1);
            else que.push(j + 1);
            if (i % W == 0) {
                if (mod) {
                    mod1.push_back(st);
                    st = stack<ll>();
                    mod = 0;
                } else {
                    mod0.push_back(que);
                    que = queue<ll>();
                    mod = 1;
                }
            }
        }
    }
    REP (k, H) {
        REP (j, W) {
            if (k % 2 == 0) {
                cout << mod0[k / 2].front() << " ";
                mod0[k / 2].pop();
            } else {
                cout << mod1[k / 2].top() << " ";
                mod1[k / 2].pop();
            }
        }
        cout << endl;
    }
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(H, W, N, std::move(a));
    return 0;
}

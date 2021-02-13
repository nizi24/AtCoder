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


void solve(long long N, std::vector<long long> a){
    ll count = 0;
    set<ll> st;
    REP (i, N) {
        if (a[i] >= 1 && a[i] <= 399) st.insert(0);
        else if (a[i] >= 400 && a[i] <= 799) st.insert(1);
        else if (a[i] >= 800 && a[i] <= 1199) st.insert(2);
        else if (a[i] >= 1200 && a[i] <= 1599) st.insert(3);
        else if (a[i] >= 1600 && a[i] <= 1999) st.insert(4);
        else if (a[i] >= 2000 && a[i] <= 2399) st.insert(5);
        else if (a[i] >= 2400 && a[i] <= 2799) st.insert(6);
        else if (a[i] >= 2800 && a[i] <= 3199) st.insert(7);
        else if (a[i] >= 3200) count++;
    }
    ll size = st.size();
    cout << max(size, 1LL);
    cout << " " << size + count << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}

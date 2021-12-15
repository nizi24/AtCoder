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
#define rall(x) (x).rbegin(),(x).rend()
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


void solve(long long N, long long K, std::vector<long long> t, std::vector<long long> d){
    map<ll, vector<ll>> sushi;
    REP (i, N) sushi[t[i]-1].push_back(d[i]);
    for (auto &su : sushi) sort(rall(su.second));

    priority_queue<ll, vector<ll>, greater<ll>> ate;
    priority_queue<ll> yet;

    ll sum = 0, kind = 0;
    for (auto su : sushi) {
        ate.push(su.second[0]);
        sum += su.second[0];
        kind++;
        for (int i = 1; i < su.second.size(); i++) {
            yet.push(su.second[i]);
        }
    }

    ll ate_size = ate.size();
    REP (i, K-ate_size) {
        ate.push(yet.top());
        sum += yet.top();
        yet.pop();
    }

    REP (i, ate_size-K) {
        yet.push(ate.top());
        sum -= ate.top();
        kind--;
        ate.pop();
    }

    ll ans = 0;
    for (ll i = kind; i > 0; i--) {
        chmax(ans, sum + i * i);
        if (yet.empty()) break;
        else if (yet.top() > ate.top()) {
            ate.push(yet.top());
            sum = sum + yet.top() - ate.top();
            ate.pop();
            yet.pop();
        } else break;
    }
    
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> t(N);
    std::vector<long long> d(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, K, std::move(t), std::move(d));
    return 0;
}

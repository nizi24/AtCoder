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


void solve(long long H, long long W, std::vector<std::vector<long long>> a){
    queue<pair<int, int>> que;

    REP (i, H) {
        if (i % 2 == 0) {
            REP (j, W) {
                if (a[i][j] % 2 != 0) {
                    que.push({j + 1, i + 1});
                }
            }
        } else {
            for (int j = W - 1; j >= 0; j--) {
                if (a[i][j] % 2 != 0) {
                    que.push({j + 1, i + 1});
                }
            }
        }
    }

    queue<pair<pair<ll, ll>, pair<ll, ll>>> ans;
    while (!que.empty()) {
        auto from = que.front();
        que.pop();
        if (que.empty()) break;
        
        auto to = que.front();
        que.pop();

        bool odd = (from.second % 2 != 0);
        int i = from.first; int j = from.second;
        while ((i != to.first || j != to.second) && j <= H) {
            if (odd) {
                while (i < W && (j < to.second || i < to.first)) {
                    ans.push({{j, i}, {j, i + 1}});
                    i++;
                }
                odd = 0;
            } else {
                while (i > 1 && (j < to.second || i > to.first)) {
                    ans.push({{j, i}, {j, i - 1}});
                    i--;
                }
                odd = 1;
            }
            if (i == to.first && j == to.second) break;
            j++;
            if (j <= H) ans.push({{j - 1, i}, {j, i}});
        }
    }

    c(ans.size())
    while (!ans.empty()) {
        auto v = ans.front();
        c(v.first.first << " " << v.first.second << " " << v.second.first << " " << v.second.second)
        ans.pop();
    }
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::vector<long long>> a(H, std::vector<long long>(W));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            scanf("%lld",&a[i][j]);
        }
    }
    solve(H, W, std::move(a));
    return 0;
}

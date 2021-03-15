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


void solve(long long H, long long W, std::vector<std::string> S){
    vector<vector<ll>> h(H+10, vector<ll>(W+10, 0));
    vector<vector<ll>> w(H+10, vector<ll>(W+10, 0));

    REP (i, W) {
        REP (j, H) {
            ll k = j;
            while (k < H && S[k][i] == '.') k++;
            REP (l, k - j) w[j + l][i] = k - j;
            j = k;
        }
    }

    REP (i, H) {
        REP (j, W) {
            ll k = j;
            while (k < W && S[i][k] == '.') k++;
            REP (l, k - j) h[i][j + l] = k - j;
            j = k;
        }
    }

    ll max = 0;
    REP (i, H) {
        REP (j, W) {
            chmax(max, h[i][j] + w[i][j] - 1);
        }
    }
    c(max)
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::string> S(H+1);
    for(int i = 0 ; i < H ; i++){
        std::cin >> S[i];
    }
    solve(H, W, std::move(S));
    return 0;
}

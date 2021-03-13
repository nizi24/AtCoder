#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
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

const string YES = "Yes";
const string NO = "No";

struct UnionFind {
    vector<long long> par, siz;

    UnionFind(long long n) : par(n, -1) , siz(n, 1) { }

    // 根を求める
    long long root(long long x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか (根が一致するかどうか)
    bool issame(long long x, long long y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(long long x, long long y) {
        x = root(x), y = root(y);
        if (x == y) return false; 
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    long long size(long long x) {
        return siz[root(x)];
    }
};

void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> C, std::vector<long long> d){
    UnionFind G(N);
    REP (i, M) G.unite(C[i], d[i]);

    map<ll, vector<ll>> mp;
    REP (i, N) mp[G.root(i + 1)].push_back(i);

    for (auto m : mp) {
        ll smA = 0;
        ll smB = 0;
        REP (i, m.second.size()) {
            smA += a[m.second[i]];
            smB += b[m.second[i]];
        }
        if (smA != smB) {
            c(NO)
            return;
        }
    }
    c(YES)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    std::vector<long long> b(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&b[i]);
    }
    std::vector<long long> C(M);
    std::vector<long long> d(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&C[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, M, std::move(a), std::move(b), std::move(C), std::move(d));
    return 0;
}

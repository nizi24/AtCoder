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

// UnionFind構造体
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

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> T(Q), X(Q), Y(Q), V(Q);
    REP (i, Q) cin >> T[i] >> X[i] >> Y[i] >> V[i];

    vector<ll> v(N, -1), w(N+1, -1);
    REP (i, Q) if (!T[i]) v[X[i]-1] = V[i];

    w[0] = 0, w[N] = 0;
    REP (i, N-1) {
        if (w[i] == -1) {
            if (v[i] != -1) w[i + 1] = v[i];
        } else {
            if (i % 2 == 0) w[i + 1] = v[i] + w[i];
            else w[i + 1] = w[i] - v[i];
        }
    }

    REP (i, N) cout << v[i] << " ";
    cout << endl;
    REP (i, N) cout << w[i] << " ";
    cout << endl;

    UnionFind Uf(N+1);
    REP (i, Q) {
        if (!T[i]) {
            Uf.unite(X[i], Y[i]);
        } else {
            if (Uf.issame(X[i], Y[i])) {
                if (X[i] < Y[i]) cout << w[Y[i]-1] - w[X[i]-1] + (Y[i] % 2 == 0 ? -V[i] : V[i]) << endl;
                else cout << w[X[i]-1] - w[Y[i]-1] + (Y[i] % 2 == 0 ? -V[i] : V[i]) << endl;
            } else cout << "Ambiguous" << endl;
        }
    }
    
    return 0;
}

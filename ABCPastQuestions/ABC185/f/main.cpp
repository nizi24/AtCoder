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

struct SegTree {
    int n; // 葉の数
    vector<long long> node; // 完全2分木

    // 初期化
    SegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, 0); // 0で初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = v[i]; // 葉を初期化
        // 下から順に葉以外のnodeを初期化
        for (int i = n-2; i >= 0; i--) node[i] = node[i*2+1] ^ node[i*2+2];
    }

    // 更新
    void update(int i, long long x) { // iは数列の添字(0-index)
        i += n-1; // 葉はn-1から始まる
        node[i] ^= x; // 葉を更新
        while (i > 0) { // 親に更新を伝搬
            i = (i-1)/2; // 親の添字
            node[i] = node[i*2+1] ^ node[i*2+2]; // 左の子: i*2+1, 右の子: i*2+2
        }
    }

    // クエリ処理
    // [s, t)を探索
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, long long &ans) { find_query(s, t, 0, n, 0, ans); }

    // 数直線を書いてシミレーションしてみるとイメージしやすい 
    void find_query(int s, int t, int l, int r, int n, long long &ans) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans ^= node[n];
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
        }
    }

    // デバック用
    void output() {
        for (int i = 0; i < n*2-1; i++) cout << node[i] << " ";
    }

};

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), T(Q), X(Q), Y(Q);
    REP (i, N) cin >> A[i];
    REP (i, Q) cin >> T[i] >> X[i] >> Y[i];

    auto segtree = SegTree(A);
    REP (i, Q) {
        if (T[i] == 1) segtree.update(X[i]-1, Y[i]);
        else {
            long long ans = 0;
            segtree.find(X[i]-1, Y[i], ans);
            c(ans)
        }
    }

    return 0;
}

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
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

struct RMQ_RUQ_LazySegTree {
    int n; // 葉の数
    vector<long long> node; // 完全2分木
    vector<long long> lazy; // 遅延配列

    // 初期化
    RMQ_RUQ_LazySegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1,  0); // INFで初期化
        lazy.resize(n*2-1, 0); // 遅延配列も初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = v[i]; // 葉を初期化
        // 下から順に葉以外のnodeを初期化
        for (int i = n-2; i >= 0; i--) node[i] = max(node[i*2+1], node[i*2+2]);
    }

    void eval(int k) {
        if (lazy[k] != 0) { // lazy[k]がINFでない場合、伝播&更新の反映
            node[k] = lazy[k];
            if (k < n-1) { // 子に伝搬
                lazy[k*2+1] = lazy[k];
                lazy[k*2+2] = lazy[k];
            }
            lazy[k] = 0;
        }
    }

    // クエリ処理
    // [s, t)を探す
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, long long &ans) { find_query(s, t, 0, n, 0, ans); }

    void find_query(int s, int t, int l, int r, int n, long long &ans) {
        eval(n); // 普通のセグメント木と違うのはここだけ
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans = max(ans, node[n]);
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
        }
    }

    // [s, t)にxを加算
    // 再帰的に更新するために呼び出す側を別の関数に
    void add(int s, int t, long long x) { add_query(s, t, 0, n, 0, x); }

    void add_query(int s, int t, int l, int r, int n, long long x) {
        eval(n);
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) {
            lazy[n] = x; // 値を更新
            eval(n);
        } else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            add_query(s, t, l, (r+l)/2, n*2+1, x); // 左下の子を更新
            add_query(s, t, (r+l)/2, r, n*2+2, x);  // 右下の子を更新
            node[n] = max(node[n*2+1], node[n*2+2]);
        }
    }

    // デバック用
    void output() {
        for (int i = 0; i < n*2-1; i++) cout << node[i] << " ";
    }

};


int main() {
    ll W, N;
    cin >> W >> N;
    vector<ll> L(N), R(N);
    REP (i, N) cin >> L[i] >> R[i];

    vector<ll> w(W+2, 0);
    auto segtree = RMQ_RUQ_LazySegTree(w);

    REP (i, N) {
        ll mx = 0;
        segtree.find(L[i], R[i]+1, mx);
        segtree.add(L[i], R[i]+1, mx+1);
        cout << mx + 1 << endl;
    }

    return 0;
}
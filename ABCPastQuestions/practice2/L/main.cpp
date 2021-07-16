#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__ 


struct LazySegTree {
    int n; // 葉の数
    // 0: 0の数, 1: 1の数, 2: 転倒数
    vector<tuple<ll, ll, ll>> node; // 完全2分木
    vector<bool> lazy; // 遅延配列

    // 初期化
    LazySegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1,  {0, 0, 0});
        lazy.resize(n*2-1, 0);

        for (int i = 0; i < sz; i++) {
            if (v[i]) get<1>(node[n-1+i]) = 1;
            else get<0>(node[n-1+i]) = 1;
        }
        // 下から順に葉以外のnodeを初期化
        for (int i = n-2; i >= 0; i--) {
            get<0>(node[i]) = get<0>(node[i*2+1]) + get<0>(node[i*2+2]);
            get<1>(node[i]) = get<1>(node[i*2+1]) + get<1>(node[i*2+2]);
            get<2>(node[i]) = get<2>(node[i*2+1]) + get<2>(node[i*2+2]) + get<1>(node[i*2+1]) * get<0>(node[i*2+2]);
        }
    }

    void eval(int k) {
        if (lazy[k]) { // lazy[k]が1の場合、伝播&更新の反映
            swap(get<0>(node[k]), get<1>(node[k]));
            get<2>(node[k]) = get<0>(node[k]) * get<1>(node[k]) - get<2>(node[k]);
            if (k < n-1) { // 子に伝搬
                lazy[k*2+1] = 1-lazy[k*2+1];
                lazy[k*2+2] = 1-lazy[k*2+2];
            }
            lazy[k] = 0;
        }
    }

    // クエリ処理
    // [s, t)を探す
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, long long &ans) {
        long long black = 0;
        long long white = 0;
        find_query(s, t, 0, n, 0, ans, black, white);
    }

    void find_query(int s, int t, int l, int r, int n, long long &ans, long long &black, long long &white) {
        eval(n); // 普通のセグメント木と違うのはここだけ
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) {
            ans += black * get<0>(node[n]);
            white += get<0>(node[n]);
            black += get<1>(node[n]);
            ans += get<2>(node[n]);

            // cout << s << t << l << r << " " << n << " " << ans << " " << white << " " << black << endl;
        } else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans, black, white); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans, black, white);  // 右下の子を探索
        }
    }


    void update(int s, int t) { update_query(s, t, 0, n, 0); }

    void update_query(int s, int t, int l, int r, int n) {
        eval(n);
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) {
            lazy[n] = 1-lazy[n];
            eval(n);
        } else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            update_query(s, t, l, (r+l)/2, n*2+1); // 左下の子を更新
            update_query(s, t, (r+l)/2, r, n*2+2);  // 右下の子を更新

            get<0>(node[n]) = get<0>(node[n*2+1]) + get<0>(node[n*2+2]);
            get<1>(node[n]) = get<1>(node[n*2+1]) + get<1>(node[n*2+2]);
            get<2>(node[n]) = get<2>(node[n*2+1]) + get<2>(node[n*2+2]) + get<1>(node[n*2+1]) * get<0>(node[n*2+2]);;
        }
    }

    // デバック用
    void output() {
        for (int i = 0; i < n*2-1; i++) cout << get<0>(node[i]) << " " << get<1>(node[i]) << " " << get<2>(node[i]) << " | ";
        cout << endl;
    }

};

void solve(long long N, long long Q, std::vector<long long> A, std::vector<long long> T, std::vector<long long> L, std::vector<long long> R) {
    auto segtree = LazySegTree(A);
    REP (i, Q) {
        if (T[i] == 1) {
            segtree.update(L[i]-1, R[i]);
        } else {
            long long ans = 0;
            segtree.find(L[i]-1, R[i], ans);
            cout << ans << endl;
        }
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> T(Q);
    std::vector<long long> L(Q);
    std::vector<long long> R(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&T[i]);
        scanf("%lld",&L[i]);
        scanf("%lld",&R[i]);
    }
    solve(N, Q, std::move(A), std::move(T), std::move(L), std::move(R));
    return 0;
}

#else  // INCLUDED_MAIN

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
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}


// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// // 任意長整数型
// using Bint = mp::cpp_int;
// // 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
// using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

#define MD 1000000007
using mint = Fp<MD>;

// 二項係数
const int MAX = 510000; // 問題ごとに変更する
const int MOD = 1000000007; // 問題ごとに変更する

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/* encode: ランレングス圧縮を行う
*/
vector<pair<char, long long>> encode(const string& str) {
    int n = (long long)str.size();
    vector<pair<char, long long>> ret;
    for (long long l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, long long>>& code) {
    string ret = "";
    for (auto p : code) {
        for (long long i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}

struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

// UnionFied構造体
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

#endif  // INCLUDED_MAIN

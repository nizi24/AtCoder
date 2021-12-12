#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__ 


struct RSQ_SegTree {
    int n; // 葉の数
    vector<long long> node; // 完全2分木

    // 初期化
    RSQ_SegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, 0); // 0で初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = v[i]; // 葉を初期化
        for (int i = n-2; i >= 0; i--) node[i] = node[i*2+1] + node[i*2+2]; // 下から順に葉以外のnodeを初期化
    }

    // 更新
    void update(int i) { // iは数列の添字(0-index), xは加算する値
        i += n-1; // 葉はn-1から始まる
        node[i]--;
        while (i > 0) { // 親に更新を伝搬
            i = (i-1)/2; // 親の添字
            node[i] = node[i*2+1] + node[i*2+2]; // 左の子: i*2+1, 右の子: i*2+2
        }
    }

    // クエリ処理
    // [s, t)を探す
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, long long &ans) { find_query(s, n, 0, n, 0, ans); }

    void find_query(int s, int t, int l, int r, int n, long long &ans) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans += node[n];
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


void solve(long long N, std::vector<long long> A, std::vector<long long> B) {
    ll ans = 0;

    vector<pair<ll, ll>> a;
    REP (i, N) a.push_back({A[i], i});
    sort(rall(a));

    vector<ll> z(N);
    map<ll, ll> m, m2;
    REP (i, N) m[B[i]]++;

    ll cnt = 0;
    for (auto q : m) {
        z[cnt] = q.second;
        m2[q.first] = cnt;
        cnt++;
    }

    RSQ_SegTree segtree = RSQ_SegTree(z);

    vector<ll> atode;
    ll pre = -1;
    REP (i, N) {
        if (pre != a[i].first) {
            for (auto s : atode) segtree.update(s);
            atode.clear();
        }
        ll c1 = 0;
        segtree.find(m2[B[a[i].second]], c1);
        ans += c1;
        atode.push_back(m2[B[a[i].second]]);
        pre = a[i].first;
    }
    c(ans);
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&B[i]);
    }
    solve(N, std::move(A), std::move(B));
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
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

// 可変長出力
void _c() { cout << '\n'; }
template <class T, class... U>
void _c(T &&x, U &&...y) {
  cout << ' ' << x;
  _c(forward<U>(y)...);
}
void c() { _c(); };
template <class T, class... U>
void c(T &&x, U &&...y) {
  cout << x;
  _c(forward<U>(y)...);
}

// __int128_tを出力する
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

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

vector<int> Z_algorithm(string S) {
    vector<int> Z(S.size(), 0);

    // i: 現在探索している範囲の左端
    // j: 一致している長さ
    int i = 1, j = 0, l = S.size();

    while (i < l) {
        // 愚直に延長する
        while (i + j < l && S[j] == S[i + j]) j++;

        Z[i] = j;

        // 一つも一致しなかった場合
        if (j == 0) {
            i++;
            continue;
        }

        // 過去に探索した結果を利用
        // (k + Z[k] < j): 現在探索している範囲をはみ出さないようにしている
        // はみ出しそうな場合、次に持ち越し
        int k = 1;
        while (i + k < l && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }

        // (i + k - 1)まではZ配列が確定しているので左端をずらす
        i += k;
        // 左端をずらした分、一致部分が短くなる
        j -= k;
    }

    Z[0] = l;
    return Z;
}

// トポロジカルソート(辞書順)
vector<int> topological_sort(int N, vector<vector<int>> G) {
    vector<int> enter(N, 0), seen(N, 0);
    REP (i, N) for (auto nx : G[i]) enter[nx]++;

    priority_queue<int, vector<int>, greater<int>> que;
    REP (i, N) {
        if (!enter[i]) {
            que.push(i);
            seen[i] = 1;
        }
    }

    vector<int> result;
    while (!que.empty()) {
        int n = que.top();
        que.pop();

        result.push_back(n);
        for (auto nx : G[n]) {
            enter[nx]--;
            if (!seen[nx] && !enter[nx]) {
                que.push(nx);
                seen[nx] = 1;
            }
        }
    }

    return result;
}

#endif  // INCLUDED_MAIN

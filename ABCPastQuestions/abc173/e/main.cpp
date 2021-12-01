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

void solve(long long N, long long K, std::vector<long long> A){
    mint sum = 1;
    vector<ll> pos, neg;
    REP (i, N) {
        if (A[i] > 0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
        sum *= A[i];
    }
    sort(rall(pos));
    sort(all(neg));
    mint ans = 1;
    if (N == K) {
        c(sum);
        return;
    } else if (pos.size() == 0) {
        if (K % 2 != 0) REP (i, K) ans *= neg[N-i-1];
        else REP (i, K) ans *= neg[i];
        c(ans);
        return;
    } else {
        int pos_i = 0, neg_i = 0;
        int pos_size = pos.size(), neg_size = neg.size();
        if (K % 2 == 1) {
            ans *= pos[0];
            pos_i++;
            pos_size--;
        }
        REP (i, K/2) {
            if (pos_size >= 2 && neg_size >= 2) {
                ll p = pos[pos_i] * pos[pos_i + 1];
                ll n = neg[neg_i] * neg[neg_i + 1];
                if (p > n) {
                    ans *= p;
                    pos_i += 2;
                    pos_size -= 2;
                } else {
                    ans *= n;
                    neg_i += 2;
                    neg_size -= 2;
                }
            } else if (pos_size >= 2) {
                ans *= pos[pos_i] * pos[pos_i + 1];
                pos_i += 2;
                pos_size -= 2;
            } else if (neg_size >= 2) {
                ans *= neg[neg_i] * neg[neg_i + 1];
                neg_i += 2;
                neg_size -= 2;
            } else {
                ans *= neg[neg_i] * pos[pos_i];
            }
        }
    }
    c(ans);
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, std::move(A));
    return 0;
}

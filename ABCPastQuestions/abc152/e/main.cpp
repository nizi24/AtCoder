#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<class T>
inline T sum(T n){return n*(n+1)/2;}

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

vector<int> sieve(int n){
    vector<int> min_factor(n+1);

    for(int i = 0; i <= n; i++) min_factor[i] = i;

    for(int i = 2; i*i <= n; i++){
        if(min_factor[i] == i){
            for(int j = 2; i*j <= n; j++){
                if(min_factor[i*j] > i){
                    min_factor[i*j] = i;
                }
            }
        }
    }
    return min_factor;
}

vector<int> factor(vector<int> &min_factor, int m){
    vector<int> ans;
    while(m > 1){
        ans.push_back(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}

void solve(long long N, std::vector<long long> A){
	auto min_factor = sieve(1000010); // 事前準備

	map<int, int> primes; // 素因数の最大数を格納
	REP (i, N) {
		// 素因数分解 O(logA[i])
		auto p = factor(min_factor, A[i]);
		map<int, int> mp; // A[i]の素因数を格納
		for (auto m : p) chmax(primes[m], ++mp[m]);
	}

	// 最小公倍数を計算
	mint LCM = 1;
	for (auto p : primes) LCM *= modpow(mint(p.first), p.second);

	// 答えを計算
	mint ans = 0;
	REP (i, N) ans += LCM / mint(A[i]);
	cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

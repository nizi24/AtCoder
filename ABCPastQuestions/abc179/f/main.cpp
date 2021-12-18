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

struct RUQ_SegTree {
    int n; // 葉の数
    // first: nodeの値, second: 更新された時間
    vector<pair<long long, int>> node; // 完全2分木

    // 初期化
    RUQ_SegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, {(1LL<<31)-1, -1}); // 2^31-1で初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = {v[i], 0}; // 葉を初期化
    }

    // 取得
    long long get(int i) { // iは数列の添字(0-index)
        long long ans = (1LL<<31)-1;
        long long ans_i = -1;
        i += n-1; // 葉はn-1から始まる
        // 更新された時間が最新ならans, ans_iを変更
        if (ans_i < node[i].second) {
            ans = node[i].first;
            ans_i = node[i].second;
        }
        while (i > 0) { // 親の値を確認
            i = (i-1)/2; // 親の添字
            // // 更新された時間が最新ならans, ans_iを変更
            if (ans_i < node[i].second) {
                ans = node[i].first;
                ans_i = node[i].second;
            }
        }
        return ans;
    }

    // [s, t)をxに更新
    // 再帰的に更新するために呼び出す側を別の関数に
    void update(int s, int t, long long x, int i) { update_query(s, t, 0, n, 0, x, i); }

    void update_query(int s, int t, int l, int r, int n, long long x, int i) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) node[n] = {min(x, node[n].first), (x < node[n].first ? i : node[n].second)};
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            update_query(s, t, l, (r+l)/2, n*2+1, x, i); // 左下の子を更新
            update_query(s, t, (r+l)/2, r, n*2+2, x, i);  // 右下の子を更新
        }
    }

    // デバック用
    void output() {
        for (int i = 0; i < n*2-1; i++) cout << node[i].first << " " << node[i].second << " | ";
        cout << endl;
    }

};

int main(){
    ll N, Q;
	cin >> N >> Q;

	vector<ll> h(N+1, N), w(N+1, N);
	auto tate = RUQ_SegTree(h);
	auto yoko = RUQ_SegTree(w);

	ll ans = (N-2) * (N-2);
	REP (i, Q) {
		ll t, x;
		cin >> t >> x;
		if (t == 1) {
			ans -= yoko.get(x) - 2;
			tate.update(1, yoko.get(x), x, i+1);
		} else {
			ans -= tate.get(x) - 2;
			yoko.update(1, tate.get(x), x, i+1);
		}
	}
	cout << ans << endl;

    return 0;
}

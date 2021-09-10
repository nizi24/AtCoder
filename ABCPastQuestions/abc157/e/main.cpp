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

struct SegTree {
    int n; // 葉の数
    vector<vector<int>> node; // 完全2分木

    // 初期化
    SegTree(string S) {
        int sz = S.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, vector<int>(26, 0)); // 0で初期化

        for (int i = 0; i < sz; i++) node[n-1+i][S[i]-'a']++;
        for (int i = n-2; i >= 0; i--) {
			REP (j, 26) node[i][j] = node[i*2+1][j] + node[i*2+2][j];
		}
    }

    // 更新
    void update(int i, int co, int cn) {
        i += n-1; // 葉はn-1から始まる
        node[i][co]--;
		node[i][cn]++;
        while (i > 0) { // 親に更新を伝搬
            i = (i-1)/2; // 親の添字
            node[i][co]--;
			node[i][cn]++;
        }
    }

    // クエリ処理
    // [s, t)を探す
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, set<int> &ans) { find_query(s, t, 0, n, 0, ans); }

    void find_query(int s, int t, int l, int r, int n, set<int> &ans) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) {
			REP (i, 26) if (node[n][i]) ans.insert(i);
		} else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
        }
    }

};

int main(){
	ll N, Q;
	string S;
	cin >> N >> S >> Q;

	auto segtree = SegTree(S);
	REP (i, Q) {
		int q;
		cin >> q;
		if (q == 1) {
			int j;
			char c;
			cin >> j >> c;
			segtree.update(j-1, S[j-1] - 'a', c - 'a');
			S[j-1] = c;
		} else {
			int l, r;
			cin >> l >> r;
			set<int> ans;
			segtree.find(l-1, r, ans);

			cout << ans.size() << endl;
		}
	}

    return 0;
}

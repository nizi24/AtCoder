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



int main(){
	int H, W, K;
	cin >> H >> W >> K;
	vector<vector<int>> s(H, vector<int>(W));
	REP (i, H) REP (j, W) {
		char ch;
		cin >> ch;
		s[i][j] = ch - '0';
	}

	int ans = INF;

	// 横方向の分割の仕方でbit全探索
	// 縦方向は貪欲で計算
	for (int bit = 0; bit < (1<<(H-1)); bit++) {
		vector<int> S;
		for (int i = 0; i < (H-1); i++) {
			if (bit & (1<<i)) {
				S.push_back(i);
			}
		}

		// siz: 横に分割したときにチョコレートが何個に分かれたか
		// cut: 分割回数
		int siz = S.size()+1, cut = siz-1;
		bool flag = false; // 条件を満たさないときにフラグを立てる
		// cnt[i]: 上からiグループ目のホワイトチョコの数を集計
		vector<int> cnt(siz, 0);

		REP (j, W) {

			int iter = 0;
			// cur[i]: j列目の上からiグループ目のホワイトチョコの数
			vector<int> cur(siz, 0);
			REP (i, H) {
				cur[iter] += s[i][j];

				if (siz-1 > iter && S[iter] == i) iter++;
			}

			bool change = 0; // cutするならchange = 1にする
			REP (i, siz) {
				if (cur[i] > K) flag = 1;

				// Kを超えないならグループに加算
				if (cur[i] + cnt[i] <= K) cnt[i] += cur[i];
				else change = 1; // 超えるならリセット
			}

			// 切る
			if (change) {
				cut++;
				// グループごとの集計をリセット
				REP (i, siz) cnt[i] = cur[i];
			}

			if (flag) break;
		}

		if (!flag) chmin(ans, cut);
	}

	c(ans); // 出力

    return 0;
}

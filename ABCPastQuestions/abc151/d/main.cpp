#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define MD 1000000007
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define EPS14  1.0E-14
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

int main(){
    ll H, W;
	cin >> H >> W;
	vector<string> S(H);
	REP (i, H) cin >> S[i];

	ll ans = 0;
	REP (i, H) {
		REP (j, W) {
			// スタート地点が壁の場合 cotinue
			if (S[i][j] == '#') continue;

			queue<pair<ll, ll>> que;
			vector<vector<ll>> dist(H, vector<ll>(W, -1));
			dist[i][j] = 0;
			que.push({i, j});

			while (!que.empty()) {
				auto v = que.front();
				que.pop();

				ll d = dist[v.first][v.second];
				// 上
				if (v.first - 1 >= 0 && S[v.first - 1][v.second] == '.') {
					if (dist[v.first - 1][v.second] == -1) {
						dist[v.first - 1][v.second] = d + 1;
						que.push({v.first - 1, v.second});
					}
				}
				// 下
				if (v.first + 1 < H && S[v.first + 1][v.second] == '.') {
					if (dist[v.first + 1][v.second] == -1) {
						dist[v.first + 1][v.second] = d + 1;
						que.push({v.first + 1, v.second});
					}
				}
				// 左
				if (v.second - 1 >= 0 && S[v.first][v.second - 1] == '.') {
					if (dist[v.first][v.second - 1] == -1) {
						dist[v.first][v.second - 1] = d + 1;
						que.push({v.first, v.second - 1});
					}
				}
				// 右
				if (v.second + 1 < W && S[v.first][v.second + 1] == '.') {
					if (dist[v.first][v.second + 1] == -1) {
						dist[v.first][v.second + 1] = d + 1;
						que.push({v.first, v.second + 1});
					}
				}
			}

			// 最大距離を求める
			ll mx = 0;
			REP (k, H) {
				REP (l, W) {
					chmax(mx, dist[k][l]);
				}
			}

			chmax(ans, mx);
		}
	}

	c(ans)
    return 0;
}

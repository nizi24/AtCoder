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



int main(){
	ll H, W;
	cin >> H >> W;
	ll ch, cw, dh, dw;
	cin >> ch >> cw >> dh >> dw;
	vector<string> S(H);
	REP (i, H) cin >> S[i];

	vector<vector<ll>> dist(H, vector<ll>(W, INF));
	dist[ch-1][cw-1] = 0;
	priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> que;
	que.push({0, {ch-1, cw-1}});

	// ダイクストラ
	while (!que.empty()) {
		ll d = que.top().first;
		ll y = que.top().second.first;
		ll x = que.top().second.second;
		que.pop();

		if (d > dist[y][x]) continue;

		// 徒歩
		for (int i = -1; i <= 1; i += 2) {
			if (y + i < H && y + i >= 0 && S[y + i][x] != '#') {
				if (chmin(dist[y + i][x], d)) {
					que.push({d, {y + i, x}});
				}
			}

			if (x + i < W && x + i >= 0 && S[y][x + i] != '#') {
				if (chmin(dist[y][x + i], d)) {
					que.push({d, {y, x + i}});
				}
			}
		}

		// // ワープ使用
		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				if (abs(i) + abs(j) <= 1) continue;
				if (y + i >= H || y + i < 0) continue;
				if (x + j >= W || x + j < 0) continue;
				if (S[y + i][x + j] == '#') continue;

				if (chmin(dist[y + i][x + j], d + 1)) {
					que.push({d + 1, {y + i, x + j}});
				}
			}
		}
	}

	if (dist[dh-1][dw-1] == INF) cout << -1 << endl;
	else cout << dist[dh-1][dw-1] << endl;

    return 0;
}

#include <bits/stdc++.h>
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

int main(){
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	REP (i, H) cin >> S[i];

	vector<vector<pair<int, int>>> teleport(26);
	vector<bool> used(26, 0);
	int sy, sx, gy, gx;
	REP (i, H) {
		REP (j, W) {
			if (S[i][j] == 'S') {
				sy = i;
				sx = j;
			} else if (S[i][j] == 'G') {
				gy = i;
				gx = j;
			} else if (S[i][j] != '.' && S[i][j] != '#') {
				teleport[S[i][j] - 'a'].push_back({i, j});
			}
		}
	}

	vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	vector<vector<long long>> dist(H, vector<long long>(W, INF64));
	queue<pair<int, int>> que;
	dist[sy][sx] = 0;
	que.push({sy, sx});
	
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
	
		for (int i = 0; i < 4; i++) {
			int ny = y + direction[i][0];
			int nx = x + direction[i][1];
	
			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (S[ny][nx] == '#' || dist[ny][nx] != INF64) continue;
	
			dist[ny][nx] = dist[y][x] + 1;
			que.push({ny, nx});
		}

		// テレポート
		int num = S[y][x]-'a';
		if (num >= 0 && num < 26) {
			if (used[num]) continue;
			used[num] = true;

			REP (j, teleport[num].size()) {
				int ny = teleport[num][j].first;
				int nx = teleport[num][j].second;
				if (dist[ny][nx] == INF64) {
					dist[ny][nx] = dist[y][x] + 1;
					que.push({ny, nx});
				}
			}
		}
 	}

	cout << (dist[gy][gx] == INF64 ? -1 : dist[gy][gx]) << endl;

    return 0;
}

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

void solve(long long N, long long X, long long M){
	// times[i]回目にiが登場した
	vector<ll> times(M, -1);
	// i回目までの数列の合計値
	vector<ll> rui(M+10, 0);

	ll cur = X; // 数列のi項目
	ll ans = X;
	N--; // 初項の分を引いておく
	times[X] = 1;
	rui[1] = X;

	ll roop_times = 0;
	for (int i = 2; i <= M+1; i++) {
		if (N <= 0) {
			c(ans);
			return;
		}

		cur = cur * cur % M;

		if (times[cur] != -1) {
			// 何項でループしているか
			roop_times = i - times[cur];
			break;
		}
		times[cur] = i;
		ans += cur;
		rui[i] = ans;
		N--;
	}

	// 最後に到達した地点
	ll t = times[cur] + roop_times - 1;
	
	// 1回のループの合計値
	ll roop = rui[t] - rui[times[cur] - 1];
	// N / roop_times => ループ回数
	ans += N / roop_times * roop;

	// ループ後の余り
	N %= roop_times;
	ll amari = rui[times[cur] + N - 1] - rui[times[cur] - 1];
	ans += amari;

	cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    long long M;
    scanf("%lld",&M);
    solve(N, X, M);
    return 0;
}

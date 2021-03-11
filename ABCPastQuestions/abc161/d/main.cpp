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

void lunlun(int d, long long val, vector<ll> &all) {
	all.push_back(val);

	if (d == 10) return;

	for (int i = -1; i <= 1; i++) {
		ll v = val % 10 + i;
		if (v >= 0 && v <= 9) lunlun(d+1, val*10+v, all);
	}
}

void solve(long long K) {
	queue<ll> que;
	REP (i, 9) que.push(i + 1);
	REP (i, K-1) {
		ll q = que.front();
		que.pop();
		for (int i = -1; i <= 1; i++) {
			ll add = q % 10 + i;
			if (add >= 0 && add <= 9) que.push(q * 10 + add);
		}
	}
	c(que.front())
}

int main(){
    long long K;
    scanf("%lld",&K);
    solve(K);
    return 0;
}

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


void solve(std::string S_A, std::string S_B, std::string S_C){
	ll a = 0;
	ll b = 0;
	ll c = 0;
	ll pre = 2;
	while (true) {
		if (pre == 2) {
			a++;
			if (a == S_A.size() + 1) {
				c("A")
				break;
			}
			pre = 'c' - S_A[a - 1];
			// c("a")
		} else if (pre == 1) {
			b++;
			if (b == S_B.size() + 1) {
				c("B")
				break;
			}
			pre = 'c' - S_B[b - 1];
			// c("b")
		} else {
			c++;
			if (c == S_C.size() + 1) {
				c("C")
				break;
			}
			pre = 'c' - S_C[c - 1];
			// c("c")
		}
		// c(pre)
	}
}

int main(){
    std::string S_A;
    std::cin >> S_A;
    std::string S_B;
    std::cin >> S_B;
    std::string S_C;
    std::cin >> S_C;
    solve(S_A, S_B, S_C);
    return 0;
}

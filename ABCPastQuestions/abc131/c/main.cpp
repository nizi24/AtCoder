#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long A, long long B, long long C, long long D){
    ll c_multiple = (B - A + 1) / C;
    c_multiple += ((A - max(A % C, 0LL) + C) + (c_multiple * C) <= B);
    ll d_multiple = (B - A + 1) / D;
    d_multiple += ((A - max(A % D, 0LL) + D) + (d_multiple * D) <= B);
    ll cd_multiple = (B - A + 1) / lcm(C, D);
    cd_multiple += ((A - max(A % lcm(C, D), 0LL) + lcm(C, D)) + (cd_multiple * lcm(C, D)) <= B);
    c(B - A + 1 - c_multiple - d_multiple + cd_multiple)
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long D;
    scanf("%lld",&D);
    solve(A, B, C, D);
    return 0;
}

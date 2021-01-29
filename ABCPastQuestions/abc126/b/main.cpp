#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(std::string S){
    int s1 = stoi(S.substr(0, S.size()/2));
    int s2 = stoi(S.substr(S.size()/2));
    if (s1 >= 1 && s1 <= 12 && (s2 >= 13 || s2 == 0)) c("MMYY")
    else if (s2 >= 1 && s2 <= 12 && (s1 >= 13 || s1 == 0)) c("YYMM")
    else if (s1 >= 1 && s1 <= 12 && s2 >= 1 && s2 <= 12) c("AMBIGUOUS")
    else c("NA")
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

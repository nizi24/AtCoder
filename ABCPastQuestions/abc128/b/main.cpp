#include <bits/stdc++.h>
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

bool st(tuple<string, ll, int> A, tuple<string, ll, int> B) {
    if (get<0>(A) < get<0>(B)) return true;
    else if (get<0>(A) == get<0>(B)) {
        if (get<1>(A) > get<1>(B)) return true;
    }
    return false;
}


void solve(long long N, std::vector<std::string> S, std::vector<long long> P){
    vector<tuple<string, ll, int>> par(N);
    REP (i, N) {
        get<0>(par[i]) = S[i];
        get<1>(par[i]) = P[i];
        get<2>(par[i]) = i;
    }
    sort(par.begin(), par.end(), st);
    REP (i, N) c(get<2>(par[i]) + 1)
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> S(N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> S[i];
        scanf("%lld",&P[i]);
    }
    solve(N, std::move(S), std::move(P));
    return 0;
}

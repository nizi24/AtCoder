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


void solve(std::string S){
    ll N = S.size();
    vector<vector<ll>> vec(20, vector<ll>(N));
    REP (i, N) {
        if (S[i] == 'R') vec[0][i] = i + 1;
        else vec[0][i] = i - 1;
    }
    REP (i, 19) REP (j, N) {
        vec[i + 1][j] = vec[i][vec[i][j]];
    }
    vector<ll> res(N, 0);
    REP (i, N) res[vec[19][i]]++;
    REP (i, N) cout << res[i] << (i != N - 1 ? " " : "");
    cout << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    vector<int> n(N);
    REP (i, N) n[i] = i;
    double sum = 0;
    double count = 0;
    do {
        double cur_sum = 0;
        REP (i, N-1) {
            double dis = ((x[n[i]] - x[n[i+1]]) * (x[n[i]] - x[n[i+1]])) + (y[n[i]] - y[n[i+1]]) * (y[n[i]] - y[n[i+1]]);
            cur_sum += sqrt(dis);
        }
        sum += cur_sum;
        count++;
    } while (ALL(next_permutation, n));
    cout << std::fixed << std::setprecision(15) << (sum / count) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}

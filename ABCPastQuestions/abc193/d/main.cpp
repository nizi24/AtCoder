#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
using Graph = vector<vector<ll>>;
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


void solve(double K, std::string S, std::string T){
    ll ans = 0;
    ll s = 0;
    ll t = 0;
    map<ll, ll> cnt;
    map<ll, ll> sm;
    map<ll, ll> tm;
    REP (i, 4) {
        cnt[S[i] - '0']++;
        cnt[T[i] - '0']++;
    }
    ll s_win = 0;
    ll t_win = 0;
    S.pop_back();
    T.pop_back();
    vint ss;
    vint tt;
    REP (i, 4) {
        ss.push_back(S[i] - '0');
        tt.push_back(T[i] - '0');
    }
    REP (k, 9) {
        if (K - cnt[k + 1] <= 0) continue;
        tt.push_back(k + 1);
        double g = ((K - cnt[k + 1]) / (9 * K - 8)) * 10000;
        cnt[k + 1]++;
        REP (j, 9) {
            if (K - cnt[j + 1] <= 0) continue;
            ss.push_back(j + 1);
            REP (i, 5) {
                sm[ss[i]]++;
                tm[tt[i]]++;
            }
            REP (i, 9) {
                s += (i + 1) * pow(10, sm[i + 1]);
                t += (i + 1) * pow(10, tm[i + 1]);
            }
            // if (k == j) cnt[j + 1]--;
            double h = ((K - cnt[j + 1]) / (9 * K - 9)) * 10000;
            // if (k == j) cnt[j + 1]++;
            if (s > t) {
                s_win += g * h;
                // cout << j + 1 << " " << k + 1 << endl;
                // cout << g << " " <<  h << endl;
            } else {
                t_win += g * h;
                // cout << j + 1 << " " << k + 1 << endl;
            }
            // cout << s << " " << t << endl;
            s = 0;
            t = 0;
            ss.pop_back();
            sm.clear();
            tm.clear();
        }
        cnt[k + 1]--;
        tt.pop_back();
    }
    if (s_win >= 100000000) {
        cf(1.0)
    } else {
        cf(s_win / (double)100000000)
    }
}

int main(){
    long long K;
    scanf("%lld",&K);
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(K, S, T);
    return 0;
}

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

vector<pair<char, long long>> encode(const string& str) {
    int n = (long long)str.size();
    vector<pair<char, long long>> ret;
    for (long long l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

void solve(std::string S){
    ll N = S.size();
    ll ans = 0;
    REP (i, N) {
        ll j = i;
        while (j < N - 1 && !(S[j] == '>' && S[j + 1] ==  '<')) {
            j++;   
        }
        ll pre = ans;
        string sub = S.substr(i, j - i + 1);
        auto rle = encode(sub);
        if (rle.size() == 2) {
            ll mx = max(rle[0].second, rle[1].second);
            ll mn = min(rle[0].second, rle[1].second);
            ans += sum(mx);
            ans += sum(mn - 1);
            // cout << "mn=" << mn << " mx=" << mx << endl;
        } else {
            ans += sum(rle[0].second);
            // cout << ans - pre << endl;
        }
        // cout << sub << endl;
        i = j;
    }
    c(ans)
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

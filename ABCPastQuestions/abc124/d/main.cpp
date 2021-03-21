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

void solve(long long N, long long K, std::string S){
    auto rle = encode(S);
    ll size = rle.size();

    ll cnt = 0;
    ll max = 0;
    ll c = 0;
    ll right = 0;
    REP (i, size) {
        while (right < size && (c < K || rle[right].first == '1')) {
            if (rle[right].first == '0') c++;
            cnt += rle[right].second;
            right++;
        }

        chmax(max, cnt);

        cnt -= rle[i].second;
        if (rle[i].first == '0') c--;
    }

    c(max)
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::string S;
    std::cin >> S;
    solve(N, K, S);
    return 0;
}

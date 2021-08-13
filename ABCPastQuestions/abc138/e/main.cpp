#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}


void solve(std::string s, std::string t){
    map<char, vector<int>> mp; // 文字の登場位置を格納
    map<char, int> mp_cnt; // 文字の登場回数
    int siz = s.size(), tsiz = t.size();
    REP (i, siz) {
        mp[s[i]].push_back(i);
        mp_cnt[s[i]]++;
    }

    ll ans = 0;
    int cur = -1; // 前回使用した文字の位置
    REP (i, tsiz) {
        // 二分探索して次にt[i]が登場する位置を特定
        auto iter = upper_bound(mp[t[i]].begin(), mp[t[i]].end(), cur);
        // cur以降にt[i]が登場しない場合は最初に戻る
        if (iter == mp[t[i]].end()) {
            // そもそもt[i]がsに含まれない場合
            if (!mp_cnt[t[i]]) {
                c(-1)
                return;
            }
            ans += siz - cur - 1; // 現在地から最後の間の文字数
            ans += mp[t[i]][0] + 1; // sの最初から初めてt[i]が登場するまでの文字数
            cur = mp[t[i]][0]; // sのなかで初めてt[i]が登場する位置
        } else {
            ans += *iter - cur;
            cur = *iter;
        }
    } 

    c(ans)
}

int main(){
    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    solve(s, t);
    return 0;
}

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

void dfs(int v, vector<vector<pair<ll, ll>>> &xy, vector<ll> &A, vector<bool> &seen){

}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<vector<pair<ll, ll>>> xy(N);
    REP (i, N) {
        cin >> A[i];
        REP (j, A[i]) {
            ll x, y;
            cin >> x >> y;
            xy[i].push_back(make_pair(x, y));
        }
    }
    ll max = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        bool ok = 1;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            if (!ok) break;
            if (bit & (1 << i)) {
                cnt++;
                REP (j, A[i]) {
                    if (bit & (1 << (xy[i][j].first - 1)) && xy[i][j].second == 0 ||
                        ~bit & (1 << (xy[i][j].first - 1)) && xy[i][j].second == 1) {
                        ok = 0;
                        break;
                    }
                    // cout << xy[i][j].first << endl;
                }
            }
        }
        // cout << "ok=" << ok << " cnt=" << cnt << endl;
        if (ok) chmax(max, cnt);
    }
    cout << max << endl;
    return 0;
}
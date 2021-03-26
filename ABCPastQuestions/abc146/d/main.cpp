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



void solve(long long N, std::vector<long long> a, std::vector<long long> b){
    vector<vector<pair<ll, ll>>> G(N);
    REP (i, N-1) {
        G[a[i] - 1].push_back({b[i] - 1, i});
        G[b[i] - 1].push_back({a[i] - 1, i});
    }

    ll mx = 0;
    vector<ll> ans(N-1, 0);
    queue<pair<ll, ll>> que;
    vector<ll> dist(N, INF);
    que.push({0, -1});
    dist[0] = 0;

    while (!que.empty()) {

        auto v = que.front();
        que.pop();

        ll size = G[v.first].size();
        chmax(mx, size);

        int i = 1;
        for (auto n : G[v.first]) {
            if (dist[n.first] != INF) continue;

            if (i == v.second) i++;
            ans[n.second] = i;
            que.push({n.first, i});
            i++;

            dist[n.first] = dist[v.first] + 1;
        }
    }

    cout << mx << endl;
    REP (i, N-1) {
        cout << ans[i] << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(N, std::move(a), std::move(b));
    return 0;
}

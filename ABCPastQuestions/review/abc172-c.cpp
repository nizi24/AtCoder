#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define EPS14  1.0E-14
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    REP (i, N) cin >> A[i];
    REP (i, M) cin >> B[i];

    vector<ll> rui(M+1, 0);
    REP (i, M) rui[i+1] = rui[i] + B[i];

    ll ans = 0, time = 0;
    REP (i, N+1) {
        if (time > K) break;
        chmax(ans, i + (upper_bound(all(rui), K-time) - rui.begin()) - 1);

        if (i != N) time += A[i];
    }

    cout << ans << endl;

    return 0;
}
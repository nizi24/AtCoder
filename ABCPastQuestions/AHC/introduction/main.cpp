#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}

ll scoring(ll d, ll type, vector<ll> last, vector<ll> c, vector<vector<ll>> s) {
    ll ans = s[d-1][type];
    last[type] = d;
    REP (i, 26) ans -= c[i] * (d - last[i]);
    return ans;
}

vector<ll> init(ll &score, vector<ll> &last, vector<ll> c, vector<vector<ll>> s) {
    vector<ll> schedule(365);
    for (int i = 1; i <= 365; i++) {
        ll mx = 0, mx_score = -INF64;
        REP (j, 26) {
            if (chmax(mx_score, scoring(i, j, last, c, s))) mx = j;
        }
        score += mx_score;
        schedule[i-1] = mx;
        last[mx] = i;
    }
    return schedule;
}

int main() {
    int D;
    cin >> D;
    vector<long long> c(26);
    REP (i, 26) cin >> c[i];
    vector<vector<long long>> s(D, vector<long long>(26));
    REP (i, D) REP (j, 26) cin >> s[i][j];


    // 初期解
    ll score = 0;
    vector<ll> last(26, 0);
    vector<ll> schedule = init(score, last, c, s);

    // 出力
    REP (i, D) cout << schedule[i] + 1 << endl;

    return 0;
}
 
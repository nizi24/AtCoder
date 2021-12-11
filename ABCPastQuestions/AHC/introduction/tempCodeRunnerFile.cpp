#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}

ll score(ll d, ll type, vector<ll> &last, vector<ll> c, vector<vector<ll>> s) {
    ll ans = s[d][type];
    last[type] = d;
    REP (i, 26) ans -= c[i] * (d - last[i]);
    return ans;
}

int main() {
    int D;
    cin >> D;
    vector<long long> c(26);
    REP (i, 26) cin >> c[i];
    vector<vector<long long>> s(D, vector<long long>(26));
    REP (i, D) REP (j, 26) cin >> s[i][j];
    vector<long long> t(D);
    REP (i, D) cin >> t[i];

    ll ans = 0;
    vector<ll> last(26, 0);
    REP (i, D) {
        ans += score(i+1, t[i]-1, last, c, s);
        cout << ans << endl;
    }


    return 0;
}

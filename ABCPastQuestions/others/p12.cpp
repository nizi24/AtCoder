#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}

set<vector<int>> st;
void dfs(vector<int> vec, vector<bool> &used, vector<vector<int>> &p, int &n, int &m) {

    REP (i, m) {
        if (used[i]) continue;

        vector<int> next(n);
        REP (j, n) {
            next[p[i][j]-1] = vec[j];
        }

        if (!st.count(next)) {
            st.insert(next);
            used[i] = 1;
            dfs(next, used, p, n, m);
            used[i] = 0;
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<int> S(n);
    REP (i, n) cin >> S[i];
    cin >> m;
    vector<vector<int>> p(m, vector<int>(n));
    REP (i, m) REP (j, n) cin >> p[i][j];

    st.insert(S);
    vector<bool> used(m, 0);
    dfs(S, used, p, n, m);

    long long mn = pw(10, 15);
    vector<int> ans;
    for (auto s : st) {
        long long cur = 0;
        REP (i, n) {
            cur += pw(10, n-i) * s[i];
        }
        if (chmin(mn, cur)) ans = s;
    }

    REP (i, n) cout << ans[i] << (i == n-1 ? "" : " ");
    cout << endl;

    return 0;
}
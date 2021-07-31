#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF INT32_MAX / 2
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}

void dfs(int id, int f, vector<int> &fav, vector<vector<pair<int, int>>> &G) {

    for (auto n : G[id]) {
        if (!fav[n.first]) dfs(n.first, n.second, fav, G);
        f += fav[n.first];
    }
    fav[id] = f;
}

int main() {
    int N;
    cin >> N;
    vector<int> d(N), f(N);
    vector<string> p(N);
    REP (i, N) cin >> d[i] >> p[i] >> f[i];

    vector<vector<pair<int, int>>> G(110);
    REP (i, N) {
        if (p[i] != "None") G[stoi(p[i])].push_back({d[i], f[i]});
    }

    vector<int> fav(110, 0);
    REP (i, N) {
        if (!fav[d[i]]) dfs(d[i], f[i], fav, G);
    }

    int max_fav = 0;
    int ans = 0;
    REP (i, 110) {
        cout << i << "  " << fav[i] << endl;
        if (chmax(max_fav, fav[i])) ans = i;
    }

    cout << ans << endl;

    return 0;
}
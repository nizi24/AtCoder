#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)

map<vector<int>, vector<vector<int>>> mp;
void dfs(vector<int> cards, vector<vector<int>> &P, int &N) {

    for (auto p : P) {
        vector<int> next(N);

        REP (i, N) {
            next[p[i]] = cards[i];
        }

        mp[cards].push_back(next);
        if (!mp.count(next)) dfs(next, P, N);
    }
}

int main() {
    int N, S;
    cin >> N;
    vector<int> x(N);
    REP (i, N) cin >> x[i];
    cin >> S;
    vector<vector<int>> P(S, vector<int>(N));
    REP (i, S) REP (j, N) cin >> P[i][j];

    dfs(x, P, N);

    map<vector<int>, int> dist;
    dist[x] = 0;
    queue<vector<int>> que;
    que.push(x);

    while (!que.empty()) {
        auto p = que.front();
        que.pop();

        for (auto n : mp[p]) {
            if (!dist[n]) {
                dist[n] = dist[p] + 1;
                que.push(n);
            }
        }
    }

    vector<int> vec;
    REP (i, N) vec.push_back(i);

    if (vec == x) cout << 0 << endl;
    else if (dist[vec]) cout << dist[vec] << endl;
    else cout << -1 << endl;

    return 0;
}
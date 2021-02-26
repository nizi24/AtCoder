#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>


vector<bool> seen;
void dfs(const Graph &g, int v) {
    seen[v] = true;

    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        dfs(g, next_v);
    }
}


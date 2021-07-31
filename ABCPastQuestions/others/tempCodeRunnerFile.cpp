#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)

vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool ans = 0;
void dfs(int y, int x, int cnt, string &P, vector<string> &t, int &N, vector<vector<bool>> &seen) {
    if (cnt == P.size()) {
        ans = 1;
        return;
    }

    REP (i, 4) {
        int ny = y + direction[i][0];
        int nx = x + direction[i][1];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (seen[ny][nx]) continue;

        if (P[cnt] == t[ny][nx]) {
            seen[ny][nx] = 1;
            dfs(ny, nx, cnt+1, P, t, N, seen);
            seen[ny][nx] = 0;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> t(N);
    REP (i, N) cin >> t[i];
    int M;
    cin >> M;
    vector<string> p(M);
    REP (i, M) cin >> p[i];

    vector<vector<bool>> seen(N, vector<bool>(N, 0));
    REP (i, M) {
        ans = 0;
        REP (j, N) {
            if (ans) break;
            REP (k, N) {
                if (ans) break;
                if (t[j][k] == p[i][0]) {
                    seen[j][k] = 1;
                    dfs(j, k, 1, p[i], t, N, seen);
                    seen[j][k] = 0;
                }
            }
        }

        if (ans) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
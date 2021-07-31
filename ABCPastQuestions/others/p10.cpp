#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> b(H);
    REP (i, H) cin >> b[i];

    vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> dist(H, vector<int>(W, 0));
    queue<pair<int, int>> que;

    REP (i, H) {
        REP (j, W) {
            if (b[i][j] == '.') {
                que.push({i, j});
                dist[i][j] = 1;
            }
        }
    }

    REP (i, H) {
        REP (j, W) {
            if (b[i][j] == '#') {
                if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                    que.push({i, j});
                    dist[i][j] = 2;
                }
            }
        }
    }

    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        REP (i, 4) {
            int ny = y + direction[i][0];
            int nx = x + direction[i][1];

            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (dist[ny][nx]) continue;

            dist[ny][nx] = dist[y][x] + 1;
            que.push({ny, nx});
        }
    }

    int ans = 0;
    REP (i, H) {
        REP (j, W) ans = max(ans, dist[i][j]-1);
    }

    cout << ans << endl;

    return 0;
}
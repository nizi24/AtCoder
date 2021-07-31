#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)
const double PI=3.141592653589793;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    REP (i, H) cin >> s[i];

    vector<vector<int>> seen(H, vector<int>(W, 0));
    vector<pair<int, int>> ans;
    queue<pair<int, int>> que;
    vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    REP (i, H) {
        REP (j, W) {
            int coastline = 0, area = 0;
            if (!seen[i][j] && s[i][j] == '#') {
                seen[i][j] = 1;
                que.push({i, j});
                
                while (!que.empty()) {
                    int y = que.front().first;
                    int x = que.front().second;
                    que.pop();
                    
                    area++;

                    REP (k, 4) {
                        int ny = y + direction[k][0];
                        int nx = x + direction[k][1];

                        if (ny < 0 || nx < 0 || ny >= H || nx >= W) {
                            coastline++;
                            continue;
                        }

                        if (s[ny][nx] == '.') coastline++;
                        else if (!seen[ny][nx]) {
                            seen[ny][nx] = 1;
                            que.push({ny, nx});
                        }
                    }
                }

                ans.push_back({area, coastline});
            }
        }
    }

    sort(ans.rbegin(), ans.rend());

    REP (i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
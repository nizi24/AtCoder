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
    string S;
    cin >> S;
    vector<string> str = {"qwertyuiop", "asdfghjkl ","zxcvbnm   "};
    vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};

    int siz = S.size();
    int ans = 0;
    REP (i, siz) {
        int y, x;
        REP (j, 3) REP (k, 10) {
            if (str[j][k] == S[i]) {
                y = j;
                x = k;
            }
        }

        if (S[i] == 't' || S[i] == 'g' || S[i] == 'b') {
            if (i + 1 < siz && S[i + 1] == str[y][x + 1]) {
                ans++;
                x++;
                int j = i + 2;
                while (j < siz) {
                    bool flag = 0;
                    REP (k, 5) {
                        int ny = y + direction[k][0];
                        int nx = x + direction[k][1];

                        if (ny < 0 || nx < 0 || ny >= 3 || nx >= 10) continue;

                        if (S[j] == str[ny][nx]) {
                            y = ny; x = nx;
                            flag = 1;
                            break;
                        }
                    }
                    if (x < 5 || !flag) {
                        j--;
                        break;
                    }
                    j++;
                    ans++;
                }
                i = j;
            }
        } else if (S[i] == 'y' || S[i] == 'h' || S[i] == 'n') {
            if (i + 1 < siz && S[i + 1] == str[y][x - 1]) {
                ans++;
                x--;
                int j = i + 2;
                while (j < siz) {
                    bool flag = 0;
                    REP (k, 5) {
                        int ny = y + direction[k][0];
                        int nx = x + direction[k][1];

                        if (ny < 0 || nx < 0 || ny >= 3 || nx >= 10) continue;

                        if (S[j] == str[ny][nx]) {
                            y = ny; x = nx;
                            flag = 1;
                            break;
                        }
                    }
                    if (x >= 5 || !flag) {
                        j--;
                        break;
                    }
                    j++;
                    ans++;
                }
                i = j;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF64 INT64_MAX / 2
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}

struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};


using Graph = vector<vector<Edge>>;

int main() {
    
    int H, W;
    cin >> H >> W;
    int SY, SX, gy, gx;
    cin >> SY >> SX >> gy >> gx;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int sy = 0, sx = 0; // 始点
    vector<vector<long long>> dist(H, vector<long long>(W, INF64));
    queue<pair<int, int>> que;
    dist[sy][sx] = 0;
    que.push({sy, sx});

    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + direction[i][0];
            int nx = x + direction[i][1];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#' || dist[ny][nx] != INF64) continue;

            dist[ny][nx] = dist[y][x] + 1;
            que.push({ny, nx});
        }
    }
    
    
    
    return 0;
}
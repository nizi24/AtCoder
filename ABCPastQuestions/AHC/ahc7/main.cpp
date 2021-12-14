#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__ 

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_real_distribution<float> distr(1, 3);

// 採用するかどうか評価する
bool eval(int x1, int y1, int x2, int y2, int l, int cnt) {
    ll d = round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    if (d * 1.9 > l) return true;
    else return false;
}

int main() {
    int N = 400, M = 1995;
    vector<ll> x(N), y(N), u(M), v(M);
    REP (i, N) cin >> x[i] >> y[i];
    REP (i, M) cin >> u[i] >> v[i];

    // 距離を計算
    vector<ll> d(M);
    REP (i, M) {
        int x1 = x[u[i]], y1 = y[u[i]];
        int x2 = x[v[i]], y2 = y[v[i]];
        d[i] = round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    }

    // 解
    UnionFind Uf(N);
    REP (i, M) {
        ll l;
        cin >> l;

        // 既につながっているならスルー
        if (Uf.issame(u[i], v[i])) {
            cout << 0 << endl;
            continue;
        }

        // i番目の辺を選択しなくても連結にできるか確認
        auto test = Uf;
        for (int j = i + 1; j < M; j++) test.unite(u[j], v[j]);
        set<ll> root;
        REP (i, N) root.insert(test.root(i));
        if (root.size() > 1) {
            cout << 1 << endl;
            continue;
        }

        // 多数決をとって採用するかどうか決める
        int cnt = 0;
        REP (j, 51) {
            vector<pair<ll, ll>> D;
            D.push_back({l, i});
            for (int j = i + 1; j < M; j++) {
                D.push_back({round(d[j] * distr(eng)), j});
            }
            sort(all(D));

            test = Uf;
            REP (j, M-i) {
                if (test.unite(u[D[j].second], v[D[j].second]) && i == j) cnt++;
            }
        }

        if (cnt >= 26) {
            cout << 1 << endl;
            Uf.unite(u[i], v[i]);
        } else cout << 0 << endl;
    }

    return 0;
}


#else  // INCLUDED_MAIN

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}

// UnionFind構造体
struct UnionFind {
    vector<long long> par, siz;

    UnionFind(long long n) : par(n, -1) , siz(n, 1) { }

    // 根を求める
    long long root(long long x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか (根が一致するかどうか)
    bool issame(long long x, long long y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(long long x, long long y) {
        x = root(x), y = root(y);
        if (x == y) return false; 
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    long long size(long long x) {
        return siz[root(x)];
    }
};

#endif  // INCLUDED_MAIN
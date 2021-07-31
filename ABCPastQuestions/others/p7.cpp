#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)

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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> t(M), a(M), b(M);
    REP (i, M) cin >> t[i] >> a[i] >> b[i];

    UnionFind Uf(N+10);

    REP (i, M) {
        if (t[i]) {
            if (Uf.issame(a[i], b[i])) cout << "yes" << endl;
            else cout << "no" << endl;
        } else Uf.unite(a[i], b[i]);
    }
    

    return 0;
}
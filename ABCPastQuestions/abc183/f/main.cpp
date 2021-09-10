#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

// UnionFind構造体
struct UnionFind {
    vector<long long> par, siz;
	vector<map<int, int>> mp;

    UnionFind(long long n, vector<int> C) : par(n, -1) , siz(n, 1) , mp(n) {
		for (int i = 1; i <= n-1; i++) mp[i][C[i-1]]++;
	}

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
		for (auto m : mp[y]) mp[x][m.first] += m.second;
        return true;
    }

    // x を含むグループのサイズ
    long long size(long long x) {
        return siz[root(x)];
    }


};

int main(){
	long long N, Q;
	cin >> N >> Q;
	vector<int> C(N);
	REP (i, N) cin >> C[i];
	vector<long long> q(Q), x(Q), y(Q);
	REP (i, Q) cin >> q[i] >> x[i] >> y[i];

	UnionFind uf(N+1, C);

	REP (i, Q) {
		if (q[i] == 1) uf.unite(x[i], y[i]);
		else {
			cout << uf.mp[uf.root(x[i])][y[i]] << endl;
		}
	}
	
    return 0;
}

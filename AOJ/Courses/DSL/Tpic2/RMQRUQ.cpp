#include <bits/stdc++.h>
using namespace std;

long long INF = (1LL<<31)-1;

struct RMQ_RUQ_LazySegTree {
    int n; // 葉の数
    vector<long long> node; // 完全2分木
    vector<long long> lazy; // 遅延配列

    // 初期化
    RMQ_RUQ_LazySegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1,  INF); // INFで初期化
        lazy.resize(n*2-1, INF); // 遅延配列も初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = v[i]; // 葉を初期化
        for (int i = n-2; i >= 0; i--) node[i] = min(node[i*2+1], node[i*2+2]); // 下から順に葉以外のnodeを初期化
    }

    void eval(int k) {
        if (lazy[k] != INF) { // lazy[k]がINFでない場合、伝播&更新の反映
            node[k] = lazy[k];
            if (k < n-1) { // 子に伝搬
                lazy[k*2+1] = lazy[k];
                lazy[k*2+2] = lazy[k];
            }
            lazy[k] = INF;
        }
    }

    // クエリ処理
    // [s, t)を探す
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, long long &ans) { find_query(s, t, 0, n, 0, ans); }

    void find_query(int s, int t, int l, int r, int n, long long &ans) {
        eval(n); // 普通のセグメント木と違うのはここだけ
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans = min(ans, node[n]);
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
        }
    }

    // [s, t)にxを加算
    // 再帰的に更新するために呼び出す側を別の関数に
    void add(int s, int t, long long x) { add_query(s, t, 0, n, 0, x); }

    void add_query(int s, int t, int l, int r, int n, long long x) {
        eval(n);
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) {
            lazy[n] = x; // 値を更新
            eval(n);
        } else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            add_query(s, t, l, (r+l)/2, n*2+1, x); // 左下の子を更新
            add_query(s, t, (r+l)/2, r, n*2+2, x);  // 右下の子を更新
            node[n] = min(node[n*2+1], node[n*2+2]);
        }
    }

    // デバック用
    void output() {
        for (int i = 0; i < n*2-1; i++) cout << node[i] << " ";
    }

};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n,  INF); // 2^31-1で初期化
    auto segtree = RMQ_RUQ_LazySegTree(v);

    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            segtree.add(s, t+1, x); // 半開区間に直して呼び出し
        } else {
            int s, t;
            cin >> s >> t;
            long long ans = INF;
            segtree.find(s, t+1, ans); // 半開区間に直して呼び出し
            cout << ans << endl;
        }
    }

    // segtree.output();
}

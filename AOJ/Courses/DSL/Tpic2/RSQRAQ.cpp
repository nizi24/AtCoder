#include <bits/stdc++.h>
using namespace std;

struct RSQ_LazySegTree {
    int n; // 葉の数
    vector<long long> node; // 完全2分木
    vector<long long> lazy; // 遅延配列

    // 初期化
    RSQ_LazySegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, 0); // 0で初期化
        lazy.resize(n*2-1, 0); // 遅延配列も初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = v[i]; // 葉を初期化
        // 下から順に葉以外のnodeを初期化
        for (int i = n-2; i >= 0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k) {
        if (lazy[k]) { // lazy[k]が0でない場合、伝播&更新の反映
            node[k] += lazy[k];
            if (k < n-1) { // 子に伝搬
                lazy[k*2+1] += lazy[k]/2;
                lazy[k*2+2] += lazy[k]/2;
            }
            lazy[k] = 0;
        }
    }

    // クエリ処理
    // [s, t)の和を取得
    // 再帰的に探索するために呼び出す側を別の関数に
    void sum(int s, int t, long long &ans) { sum_query(s, t, 0, n, 0, ans); }

    void sum_query(int s, int t, int l, int r, int n, long long &ans) {
        eval(n); // 普通のセグメント木と違うのはここだけ
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans += node[n];
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            sum_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            sum_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
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
            lazy[n] += (r - l) * x; // 子にもつ葉の数だけ加算
            eval(n);
        } else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            add_query(s, t, l, (r+l)/2, n*2+1, x); // 左下の子を更新
            add_query(s, t, (r+l)/2, r, n*2+2, x);  // 右下の子を更新
            node[n] = node[n*2+1] + node[n*2+2];
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
    vector<long long> v(n,  0); // 0で初期化
    auto segtree = RSQ_LazySegTree(v);

    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            segtree.add(s-1, t, x); // 0-index, 半開区間に直して呼び出し
        } else {
            int s, t;
            cin >> s >> t;
            long long ans = 0;
            segtree.sum(s-1, t, ans); // 0-index, 半開区間に直して呼び出し
            cout << ans << endl;
        }
    }
}
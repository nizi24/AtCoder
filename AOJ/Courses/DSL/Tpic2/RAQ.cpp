#include <bits/stdc++.h>
using namespace std;

struct RSQ_SegTree {
    int n; // 葉の数
    vector<long long> node; // 完全2分木

    // 初期化
    RSQ_SegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, 0); // 0で初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = v[i]; // 葉を初期化
        for (int i = n-2; i >= 0; i--) node[i] = node[i*2+1] + node[i*2+2]; // 下から順に葉以外のnodeを初期化
    }

    // 取得
    long long get(int i) { // iは数列の添字(0-index)
        long long ans = 0;
        i += n-1; // 葉はn-1から始まる
        ans += node[i]; // 葉の値を加算
        while (i > 0) { // 親の値を加算
            i = (i-1)/2; // 親の添字
            ans += node[i];
        }
        return ans;
    }

    // [s, t)にxを加算
    // 再帰的に更新するために呼び出す側を別の関数に
    void update(int s, int t, long long x) { update_query(s, t, 0, n, 0, x); }

    void update_query(int s, int t, int l, int r, int n, long long x) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) node[n] += x;
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            update_query(s, t, l, (r+l)/2, n*2+1, x); // 左下の子を更新
            update_query(s, t, (r+l)/2, r, n*2+2, x);  // 右下の子を更新
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
    auto segtree = RSQ_SegTree(v);

    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            segtree.update(s-1, t, x); // 0-index, 半開区間に直して呼び出し
        } else {
            int i;
            cin >> i;
            cout << segtree.get(i-1) << endl; // 0-indexに直して呼び出し
        }
    }

    // segtree.output();
}

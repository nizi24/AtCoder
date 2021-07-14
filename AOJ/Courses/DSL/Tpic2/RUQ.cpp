#include <bits/stdc++.h>
using namespace std;

struct RUQ_SegTree {
    int n; // 葉の数
    // first: nodeの値, second: 更新された時間
    vector<pair<long long, int>> node; // 完全2分木

    // 初期化
    RUQ_SegTree(vector<long long> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, {(1LL<<31)-1, -1}); // 2^31-1で初期化

        for (int i = 0; i < sz; i++) node[n-1+i] = {v[i], -1}; // 葉を初期化
    }

    // 取得
    long long get(int i) { // iは数列の添字(0-index)
        long long ans = (1LL<<31)-1;
        long long ans_i = -1;
        i += n-1; // 葉はn-1から始まる
        // 更新された時間が最新ならans, ans_iを変更
        if (ans_i < node[i].second) {
            ans = node[i].first;
            ans_i = node[i].second;
        }
        while (i > 0) { // 親の値を確認
            i = (i-1)/2; // 親の添字
            // // 更新された時間が最新ならans, ans_iを変更
            if (ans_i < node[i].second) {
                ans = node[i].first;
                ans_i = node[i].second;
            }
        }
        return ans;
    }

    // [s, t)にxを加算
    // 再帰的に更新するために呼び出す側を別の関数に
    void update(int s, int t, long long x, int i) { update_query(s, t, 0, n, 0, x, i); }

    void update_query(int s, int t, int l, int r, int n, long long x, int i) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) node[n] = {x, i};
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            update_query(s, t, l, (r+l)/2, n*2+1, x, i); // 左下の子を更新
            update_query(s, t, (r+l)/2, r, n*2+2, x, i);  // 右下の子を更新
        }
    }

    // デバック用
    void output() {
        for (int i = 0; i < n*2-1; i++) cout << node[i].first << " " << node[i].second << " | ";
    }

};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n, (1LL<<31)-1); // 2^31-1で初期化
    auto segtree = RUQ_SegTree(v);

    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            // iは更新時の時間を表す
            segtree.update(s, t+1, x, i); // 半開区間に直して呼び出し
        } else {
            int i;
            cin >> i;
            cout << segtree.get(i) << endl;
        }
    }

    // segtree.output();
}

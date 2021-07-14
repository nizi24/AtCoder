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

    // 更新
    void update(int i, long long x) { // iは数列の添字(0-index), xは加算する値
        i += n-1; // 葉はn-1から始まる
        node[i] += x; // 葉に加算
        while (i > 0) { // 親に更新を伝搬
            i = (i-1)/2; // 親の添字
            node[i] = node[i*2+1] + node[i*2+2]; // 左の子: i*2+1, 右の子: i*2+2
        }
    }

    // クエリ処理
    // [s, t)を探す
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, long long &ans) { find_query(s, t, 0, n, 0, ans); }

    void find_query(int s, int t, int l, int r, int n, long long &ans) {
        // cout << s << t << l << r << " " << n << " " << ans << endl;
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans += node[n];
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
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
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) segtree.update(x-1, y); //0-indexに変換して呼び出し
        else {
            long long ans = 0;
            segtree.find(x-1, y, ans); // 0-index, 半開区間に変換して呼び出し
            cout << ans << endl;
        }
    }

    // segtree.output();
}

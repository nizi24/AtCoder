#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define MOD 1000000007
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}

struct SegTree {
    int n; // 葉の数
    vector<pair<long long, ll>> node; // 完全2分木

    // 初期化
    SegTree(int sz) {
        n = 1;
        while (n < sz) n *= 2; // 与えられた数列の項数以上の2^n個、葉を作る
        node.resize(n*2-1, {INF, INF}); // 0で初期化
}

    // 更新
    void update(int i, long long x) { // iは数列の添字(0-index), xは更新後の値
        i += n-1; // 葉はn-1から始まる
        node[i] = {x, i-n+1}; // 葉を更新
        while (i > 0) { // 親に更新を伝搬
            i = (i-1)/2; // 親の添字
            node[i] = min(node[i*2+1], node[i*2+2]); // 左の子: i*2+1, 右の子: i*2+2
        }
    }

    // クエリ処理
    // [s, t)を探索
    // 再帰的に探索するために呼び出す側を別の関数に
    void find(int s, int t, pair<ll, ll> &ans) { find_query(s, t, 0, n, 0, ans); }

    // 数直線を書いてシミレーションしてみるとイメージしやすい 
    void find_query(int s, int t, int l, int r, int n, pair<ll, ll> &ans) {
        if (r <= s || t <= l) return; // 範囲外なら終了
        // [s, t)が[l, r)を内包しているとき
        else if (s <= l && t >= r) ans = min(ans, node[n]);
        else {
            // (r+l)/2は区間の中心, 区間の中心を左端にするか、右端にするかで分岐する
            find_query(s, t, l, (r+l)/2, n*2+1, ans); // 左下の子を探索
            find_query(s, t, (r+l)/2, r, n*2+2, ans);  // 右下の子を探索
        }
    }

    // デバック用
    void output() {
        // for (int i = 0; i < n*2-1; i++) cout << node[i] << " ";
    }

};

void solve(long long N, long long M, std::string S){
    auto segtree = SegTree(N+1);
    segtree.update(0, 0);

    vector<ll> prev(N+1, -1);
    for (int i = 1; i <= N; i++) {
        if (S[i] == '1') continue;

        pair<ll, ll> tmp = {INF, -1};
        segtree.find(max(0LL, i-M), i, tmp);
        segtree.update(i, tmp.first);

        prev[i] = tmp.second;
    }

    vector<ll> ans;
    int iter = N;
    while (true) {
        if (!iter) {
            break;
        } else if (prev[iter] == -1) {
            cout << -1 << endl;
            return;
        }

        ans.push_back(iter - prev[iter]);
        iter = prev[iter];
    }

    ALL(reverse, ans);
    REP (i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::string S;
    std::cin >> S;
    solve(N, M, S);
    return 0;
}

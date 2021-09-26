#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(int i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(int i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}

vector<int> Z_algolism(string S) {
    vector<int> Z(S.size(), 0);

    // i: 現在探索している範囲の左端
    // j: 一致している長さ
    int i = 1, j = 0, l = S.size();

    while (i < l) {
        // 愚直に延長する
        while (i + j < l && S[j] == S[i + j]) j++;

        Z[i] = j;

        // 一つも一致しなかった場合
        if (j == 0) {
            i++;
            continue;
        }

        // 過去に探索した結果を利用
        // (k + Z[k] < j): 現在探索している範囲をはみ出さないようにしている
        // はみ出しそうな場合、次に持ち越し
        int k = 1;
        while (i + k < l && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }

        // (i + k - 1)まではZ配列が確定しているので左端をずらす
        i += k;
        // 左端をずらした分、一致部分が短くなる
        j -= k;
    }

    Z[0] = l;
    return Z;
}

void solve(long long N, std::string S){
    int ans = 0;
    REP (i, N) {
        string T = S.substr(i);
        auto Z = Z_algolism(T);
        for (int j = 0; j < T.size(); j++) {
            // 被っている部分はカット
            chmax(ans, min(j, Z[j]));
        }
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}

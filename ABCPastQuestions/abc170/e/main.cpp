#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define EPS14  1.0E-14
#define REP(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
ll pw(ll x, ll n){ll ret=1;while(n>0){if(n&1){ret*=x;}x *= x;n >>= 1;}return ret;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}


void solve(long long N, long long Q, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C, std::vector<long long> D){
    // 園児の現在の所属先
    vector<ll> shozoku(N+1);
    // 幼稚園
    map<ll, multiset<ll>> yochien;
    REP (i, N) {
        shozoku[i+1] = B[i];
        yochien[B[i]].insert(A[i+1]);
    }

    // 各yochienの最大レートを保持する
    multiset<ll> highest;
    for (auto m : yochien) highest.insert(*m.second.rbegin());

    REP (i, Q) {
        // 移籍前のyochienで最大のレートを持っていた場合
        auto mx = yochien[shozoku[C[i]]].rbegin();
        if (*mx == A[C[i]]) {
            // highestから削除
            highest.erase(highest.find(*mx));

            // 移籍前の幼稚園から園児を削除
            auto erase_iter = yochien[shozoku[C[i]]].find(A[C[i]]);
            yochien[shozoku[C[i]]].erase(erase_iter);

            // 移籍前の幼稚園で二番目にレートが高い園児をhighestに挿入
            if (!yochien[shozoku[C[i]]].empty()) {
                highest.insert(*mx);
            }
        } else {
            // 移籍前の幼稚園から園児を削除
            auto erase_iter = yochien[shozoku[C[i]]].find(A[C[i]]);
            yochien[shozoku[C[i]]].erase(erase_iter);
        }

        // 移籍先のyochienでこの園児が最大のレートになる場合
        mx = yochien[D[i]].rbegin();
        if (yochien[D[i]].empty()) {
            highest.insert(A[C[i]]);
        } else if (A[C[i]] > *mx) {
            highest.erase(highest.find(*mx));
            highest.insert(A[C[i]]);
        }
        // 移籍先のyochienに園児を追加
        yochien[D[i]].insert(A[C[i]]);

        // 所属表を変更
        shozoku[C[i]] = D[i];

        // 出力
        cout << *highest.begin() << endl;
    }

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> A(N+1);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i+1]);
        scanf("%lld",&B[i]);
    }
    std::vector<long long> C(Q);
    std::vector<long long> D(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&C[i]);
        scanf("%lld",&D[i]);
    }
    solve(N, Q, std::move(A), std::move(B), std::move(C), std::move(D));
    return 0;
}

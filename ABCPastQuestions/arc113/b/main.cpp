#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ll = long long;
using lint = long long;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define MD 1000000007
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
map<ll,ll> prime_fac(ll A) {map<ll,ll>mp;for(ll i=2;i*i<=A;i++){while(A%i== 0){mp[i]++;A/=i;}}if(A!=1){mp[A]=1;}return mp;}
bool is_prime(ll N){if(N<=1)return false;for(ll i=2;i*i<=N;i++){if(N%i==0) return false;}return true;}
template<class T>inline T myceil(T a,T b){return (a+(b-1))/b;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

ll s(ll a, ll x) {
    if (a == 0) {
        return 0;
    } else if (a == 1) {
        return 1;
    } else if (a == 2) {
        if (x == 1) {
            return 2;
        } else if (x == 2) {
            return 4;
        } else if (x == 3) {
            return 8;
        } else if (x == 0) {
            return 6;
        }
    } else if (a == 3) {
        if (x == 1) {
            return 3;
        } else if (x == 2) {
            return 9;
        } else if (x == 3) {
            return 7;
        } else if (x == 0) {
            return 1;
        }
    } else if (a == 4) {
        if (x == 1) {
            return 4;
        } else if (x == 0) {
            return 6;
        }
    } else if (a == 5) {
        return 5;
    } else if (a == 6) {
        return 6;
    } else if (a == 7) {
        if (x == 1) {
            return 7;
        } else if (x == 2) {
            return 9;
        } else if (x == 3) {
            return 3;
        } else if (x == 0) {
            return 1;
        }
    } else if (a == 8) {
        if (x == 1) {
            return 8;
        } else if (x == 2) {
            return 4;
        } else if (x == 3) {
            return 2;
        } else if (x == 0) {
            return 6;
        }
    } else if (a == 9) {
        if (x == 1) {
            return 9;
        } else if (x == 0) {
            return 1;
        }
    }
    return 0;
}

void solve(long long A, long long B, long long C){
    ll a = A % 10;
    vint vec(10);
    vec[0] = 1;
    vec[1] = 1;
    vec[2] = 4;
    vec[3] = 4;
    vec[4] = 2;
    vec[5] = 1;
    vec[6] = 1;
    vec[7] = 4;
    vec[8] = 4;
    vec[9] = 2;
    ll N = 0;
    REP (i, 10) if (a == i) N = vec[i];
    ll b = 0;
    if (B % N == 0 && C % N == 0) {
        b = N;
    } else {
        b = pow(B % N, C % N);
    }
    c(s(a, b % N))
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    solve(A, B, C);
    return 0;
}

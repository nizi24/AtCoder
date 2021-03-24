#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
using namespace std;
typedef vector<long long> vint;
typedef pair<long long, long long> pint;
#define INF INT32_MAX / 2
#define INF64 INT64_MAX / 2
#define EPS 0.001
#define EPS14  1.0E-14
#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define c(n) cout<<n<<endl;
#define cf(n) cout<<fixed<<setprecision(15)<<n<<endl;
template <class T>inline bool chmin(T&a,T b) {if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T&a,T b) {if(a<b){a=b;return true;}return false;}
template<class T>inline T sum(T n){return n*(n+1)/2;}
bool is_product_overflow(long long a,long long b) {long prod=a*b;return (prod/b!=a);}

int main() {

    while (true) {
        int R, N;
        scanf("%d %d", &R, &N);
        if(R == -1 && N == -1) break;

        vector<long long> X(N);
        REP (i, N) cin >> X[i];
        sort(all(X));

        int ans = 0;
        long long prev = X[0] + R;
        REP (i, N) {
            int j = i;
            while (j + 1 < N && X[j + 1] <= prev) j++;
            ans++;
            int p = X[j] + R;

            while (j + 1 < N && X[j + 1] <= p) j++;

            prev = X[min(N-1, j + 1)] + R;
            i = j;
        }

        c(ans)
    }

    return 0;
}
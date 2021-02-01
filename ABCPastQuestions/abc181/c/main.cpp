#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    int ans = 0;
    REP (i, N) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int mxY = (y[i] > y[j] && y[i] > y[k] ? i : (y[j] > y[k] ? j : k));
                int mnY = (y[i] < y[j] && y[i] < y[k] ? i : (y[j] < y[k] ? j : k));
                int middle = (mxY != i && mnY != i ? i : (mxY != j && mnY != j ? j : k));
                double tlit;
                if (y[mxY] - y[mnY] != 0) {
                    tlit = (y[mxY] - y[mnY]) / (double)(x[mxY] - x[mnY]);
                    if (tlit == (y[middle] - y[mnY]) / (double)(x[middle] - x[mnY])) ans++;
                } else {
                    if (y[middle] - y[mnY] == 0) ans++;
                }
            }
        }
    }
    cout << (ans ? YES : NO) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}

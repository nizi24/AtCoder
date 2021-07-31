#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define MOD 1000000007
#define INF INT32_MAX / 2
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

long long N, M, Q;
long long ans = 0;
void dfs(int cnt, vector<int> &vec, vector<long long> &a, vector<long long> &b, vector<long long> &c, vector<long long> &d) {
    if (cnt == N) {
        long long cur = 0;
        REP (i, Q) {
            if (vec[b[i]-1] - vec[a[i]-1] == c[i]) cur += d[i];
        }
        chmax(ans, cur);
        return;
    }

    for (int i = vec[cnt-1]; i <= M; i++) {
        vec.push_back(i);
        dfs(cnt+1, vec, a, b, c, d);
        vec.pop_back();
    }
}

void solve(long long N, long long M, long long Q, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    REP (i, M) {
        vector<int> vec = {i + 1};
        dfs(1, vec, a, b, c, d);
    }

    cout << ans << endl;
}

int main(){
    scanf("%lld",&N);
    scanf("%lld",&M);
    scanf("%lld",&Q);
    std::vector<long long> a(Q);
    std::vector<long long> b(Q);
    std::vector<long long> c(Q);
    std::vector<long long> d(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, M, Q, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}

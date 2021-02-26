#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using Graph = vector<vector<long long>>;
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

const string YES = "Yes";

vector<long long> BFS(const Graph &G, long long N) {
    vector<long long> dist(N+10, -1);
    queue<long long> que;

    dist[1] = 0;
    que.push(1);

    while (!que.empty()) {
        long long v = que.front();
        que.pop();
        
        // cout << v << " ";
        for (auto x : G[v]) {
            if (dist[x] != -1) continue;

            // cout << x << " ";
            dist[x] = v;
            que.push(x);
        }
        // cout << endl;
    }
    return dist;
}

void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B){
    Graph G(N+10);
    REP (i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    auto dist = BFS(G, N);
    REP (i, N) {
        if (dist[i + 1] == -1) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    REP (i, N-1) {
        cout << dist[i + 2] << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, M, std::move(A), std::move(B));
    return 0;
}

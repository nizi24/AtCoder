#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> happ(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> happ.at(i).at(j);
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n+1; i++) {
        chmax(dp[i][0], max(dp[i-1][1] + happ[i-1][0], dp[i-1][2] + happ[i-1][0]));
        chmax(dp[i][1], max(dp[i-1][0] + happ[i-1][1], dp[i-1][2] + happ[i-1][1]));
        chmax(dp[i][2], max(dp[i-1][0] + happ[i-1][2], dp[i-1][1] + happ[i-1][2]));
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}
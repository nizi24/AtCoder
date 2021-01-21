#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, v;
    cin >> N >> v;
    vector<int> n(N);
    for (int i = 0;i<N;i++) cin >> n.at(i);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (v == n.at(i)) ans++;
    }
    cout << ans << endl;
}
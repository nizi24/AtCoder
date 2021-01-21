#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> n(N);
    for (int i = 0;i<N;i++) cin >> n.at(i);
    int max = n.at(0);
    int min = n.at(0);
    for (int i = 1; i<N; i++) {
        if (min > n.at(i)) {
            min = n.at(i);
        } else if (max < n.at(i)) {
            max = n.at(i);
        }
    }
    cout << max - min << endl;
}
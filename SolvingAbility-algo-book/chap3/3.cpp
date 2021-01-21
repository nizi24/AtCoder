#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, v;
    cin >> N;
    vector<int> n(N);
    for (int i = 0;i<N;i++) cin >> n.at(i);
    int min = n.at(0);
    int second_min = n.at(0);
    for (int i = 1; i < N; i++) {
        if (min > n.at(i)) {
            min = n.at(i);
            second_min = min;
        } else if (second_min > n.at(i)) {
            second_min = n.at(i);
        }
    }
    cout << second_min << endl;
}
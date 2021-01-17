#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ary(n);
    for (int i = 0; i < n; i++) {
        cin >> ary.at(i).second >> ary.at(i).first;
    }

    sort(ary.begin(), ary.end());
    for (auto pair : ary) {
        printf("%d %d\n", pair.second, pair.first);
    }
}
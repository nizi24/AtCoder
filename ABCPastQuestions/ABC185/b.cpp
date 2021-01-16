#include <bits/stdc++.h>
using namespace std;

int main() {
    int bt, M, T;
    cin >> bt >> M >> T;
    vector<int> cfBegin(M);
    vector<int> cfEnd(M);
    for (int i = 0; i < M; i++) {
        cin >> cfBegin.at(i) >> cfEnd.at(i);
    }

    int btMax = bt;
    int cfCount = 0;
    bool cf = false;
    string ans = "Yes";
    for (int i = 0; i < T; i++) {
        if (cfBegin.size() > cfCount) {
            if (cfBegin.at(cfCount) == i) {
                cf = true;
            } else if (cfEnd.at(cfCount) == i) {
                cf = false;
                cfCount++;
            }
        }
        if (cf && bt < btMax) {
            bt++;
        } else {
            if (!cf) {
                bt--;
            }
        }
        if (bt <= 0) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}
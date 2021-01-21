#include <bits/stdc++.h>
using namespace std;

int triponachi(int n, vector<long long> &memo) {
    if (n == 0 || n == 1) {
        return 0;
    } else if (n == 2) return 1;
    if (memo.at(n) != -1) return memo.at(n);
    return memo.at(n) = triponachi(n - 1, memo) + triponachi(n - 2, memo) + triponachi(n - 3, memo);

}

int main() {
    int n;
    cin >> n;
    vector<long long> memo;
    memo.assign(n+1, -1);
    cout << triponachi(n, memo) << endl;
}
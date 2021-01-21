#include <bits/stdc++.h>
using namespace std;

int triponachi(int n) {
    if (n == 0 || n == 1) {
        return 0;
    } else if (n == 2) return 1;
    return triponachi(n - 1) + triponachi(n - 2) + triponachi(n - 3);

}

int main() {
    int n;
    cin >> n;
    cout << triponachi(n) << endl;
}
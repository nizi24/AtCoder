#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int ans = 1;
  for (int i = 0; i < S.size(); i++) {
    char s = S.at(i);
    if (s == '+') {
      ans += 1;
    } else if (s == '-') {
      ans -= 1;
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  string ans = "NO";
  for (int i = 0; i < data.size(); i++) {
    if (i > 0 && data.at(i) == data.at(i-1)) {
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
}

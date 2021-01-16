#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;
 
  int x = A;
  for (int i = 1; i < N + 1; i++) { 
    string sym;
    int n;
    cin >> sym >> n;
    if (sym == "+") {
      x += n;
    } else if (sym == "-") {
      x -= n;
    } else if (sym == "*") {
      x *= n;
    } else if (sym == "/") {
      if (n == 0) {
        cout << "error" << endl;
        break;
      }
      x /= n;
    }
    cout << i << ":" << x << endl;
  }
}
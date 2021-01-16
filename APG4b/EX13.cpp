#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> p(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
    sum += p.at(i);
  }
  sum /= N;
  
  for (int i = 0; i < N; i++) {
    int df = sum - p.at(i);
   	if (df >= 0) {
      cout << df << endl;
    } else {
      cout << -df << endl;
    }
  }
}
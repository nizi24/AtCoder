#include <bits/stdc++.h>
using namespace std;
#define INF INT32_MAX / 2
#define REP(i, n) for (int i = 0; i < n; i++)
template <class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
    int age;
    int left = 20, right = 36;
    cin >> age;
    int ans = 0;
    while (true) {
        int mid = left + (right - left) / 2;
        if (mid == age) {
            ans = mid;
            break;
        }
        else if (age < mid) right = mid;
        else if (age > mid) left = mid;
    }
    cout << ans << endl;
}
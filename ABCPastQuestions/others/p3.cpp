#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double PI=3.141592653589793;

int main() {
    int a, b, x, y, r, theta;
    ll L;
    cin >> a >> b >> x >> y >> r >> theta >> L;

    double X = abs(x + cos(theta * PI / 180) * L), Y = abs(y + sin(theta * PI / 180) * L);
    double ansX = fmod(X, (a - 2 * r)), ansY = fmod(Y, (b - 2 * r));

    if ((int)ceil((X - 0.0000001) /(a - 2 * r)) % 2 == 0) ansX = a - ansX;
    if ((int)ceil((Y - 0.0000001) /(b - 2 * r)) % 2 == 0) ansY = b - ansY;
    cout << ceil(Y/(b - 2 * r)) << endl;


    cout << X << " " << Y << endl;
    cout << fixed << setprecision(15) << ansX << " " << ansY << endl;

    

    return 0;
}
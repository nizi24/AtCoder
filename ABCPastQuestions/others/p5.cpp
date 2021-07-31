#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < n; i++)
const double PI=3.141592653589793;

int main() {
    int W, H, M, N;
    cin >> W >> H >> M >> N;
    vector<int> x(M), y(M), t(M), d(M), r(M);
    REP (i, M) cin >> x[i] >> y[i] >> t[i] >> d[i] >> r[i];
    vector<int> a(N), b(N);
    REP (i, N) cin >> a[i] >> b[i];

    REP (i, N) {
        bool flag = 0;
        REP (j, M) {
            double alpha = t[j] - (double)d[j] / 2.0, beta = t[j] + (double)d[j] / 2.0; 
            double dis = sqrt(pow(a[i] - x[j], 2) + pow(b[i] - y[j], 2));
            double theta = atan2(b[i] - y[j], a[i] - x[j]) * 180.0 / PI;

            if (alpha < 0) alpha = 180 + (180 - abs(alpha));
            if (beta < 0) beta = 180 + (180 - abs(beta));
            if (theta < 0) theta = 180 + (180 - abs(theta));

            if (dis <= r[j]) {
                if (beta > alpha) {
                    if (alpha <= theta && theta <= beta) flag = 1;
                } else {
                    if ((alpha <= theta && theta <= 360) || theta <= beta) flag = 1;
                }
            }
        }
        
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
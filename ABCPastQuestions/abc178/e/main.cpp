#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
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


void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    vector<pair<long long, int>> abs_xy(N), xy1(N), xy2(N);
    REP (i, N) {
        abs_xy[i] = {abs(x[i] + y[i]), i};
        xy1[i] = {x[i]-y[i], i};
        xy2[i] = {-x[i]+y[i], i};
    }

    // 昇順ソート
    ALL(sort, abs_xy);
    ALL(sort, xy1);
    ALL(sort, xy2);

    long long mx = 0;
    int l1, l2, l3, r1, r2, r3;
    l1=l2=l3=0;
    r1=r2=r3=N-1;
    REP (i, N) {
        int i1 = abs_xy[r1].second;
        int j1 = abs_xy[l1].second;
        if ((x[i1] >= x[j1] && y[i1] >= y[j1]) || (x[i1] < x[j1] && y[i1] < y[j1])) {
            chmax(mx, abs_xy[r1].first - abs_xy[l1].first);
        } else {
            if (abs(abs_xy[r1].first - abs_xy[r1-1].first) >= (abs_xy[l1].first - abs_xy[l1+1].first)) l1++;
            else r1--;
        }

        int i2 = xy1[r2].second;
        int j2 = xy1[l2].second;
        if ((x[i2] >= x[j2] && y[i2] < y[j2])) {
            chmax(mx, xy1[r2].first - xy1[l2].first);
        } else {
            if (abs(xy1[r2].first - xy1[r2-1].first) >= (xy1[l2].first - xy1[l2+1].first)) l2++;
            else r2--;
        }

        int i3 = xy2[r3].second;
        int j3 = xy2[l3].second;
        if ((x[i3] < x[j3] && y[i3] >= y[j3])) {
            chmax(mx, xy2[r3].first - xy2[l3].first);
        } else {
            if (abs(xy2[r3].first - xy2[r3-1].first) >= (xy2[l3].first - xy2[l3+1].first)) l3++;
            else r3--;
        }
    }

    cout << mx << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}

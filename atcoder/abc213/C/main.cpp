#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> A, B;
    set<int> xs, ys;
    for (int i = 0; i < N; ++i) {
        int y, x;
        cin >> y >> x;
        --y, --x;
        A.push_back(y);
        B.push_back(x);
        ys.insert(y);
        xs.insert(x);
    }

    auto yss = vector<int>(ys.begin(), ys.end());
    auto xss = vector<int>(xs.begin(), xs.end());
    for (int i = 0; i < N; ++i) {
        int y = distance(yss.begin(), upper_bound(yss.begin(), yss.end(), A[i]-1)) + 1;
        int x = distance(xss.begin(), upper_bound(xss.begin(), xss.end(), B[i]-1)) + 1;
        cout << y << " " << x << endl;
    }

    return 0;
}
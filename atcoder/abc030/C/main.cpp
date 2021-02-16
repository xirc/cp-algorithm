#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, X, Y;
    vector<int> A, B;

    cin >> N >> M >> X >> Y;
    A.assign(N, 0);
    B.assign(M, 0);
    for (auto &ai : A) cin >> ai;
    for (auto &bi : B) cin >> bi;

    int count = 0;
    int time = 0;
    while (true) {
        auto ia = lower_bound(A.begin(), A.end(), time);
        if (ia == A.end()) break;
        int ta = *ia;
        auto ib = lower_bound(B.begin(), B.end(), ta + X);
        if (ib == B.end()) break;
        int tb = *ib;
        time = tb + Y;
        ++count;
    }
    cout << count << endl;

    return 0;
}
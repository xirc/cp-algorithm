#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, T;
vector<int> ts;

int solve() {
    int X = 0;
    int b = 0, e = 0;
    for (auto t : ts) {
        if (e < t) {
            X += (e - b);
            b = t;
            e = t + T;
        } else {
            e = t + T;
        }
    }
    X += (e - b);
    return X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    ts.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> ts[i];
    }
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, X;
vector<int> V, P;

int solve() {
    int w = 0;
    for (int i = 0; i < N; ++i) {
        w += V[i] * P[i];
        if (w > X * 100)  return i + 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> X;
    V.assign(N, 0);
    P.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> V[i] >> P[i];
    }
    cout << solve() << endl;

    return 0;
}
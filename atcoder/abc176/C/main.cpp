#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> A[i];

    ll stepH = 0;
    int H = A[0];
    for (int i = 0; i < N; ++i) {
        stepH += max(0, H - A[i]);
        H = max(H, A[i]);
    }
    cout << stepH << endl;

    return 0;
}
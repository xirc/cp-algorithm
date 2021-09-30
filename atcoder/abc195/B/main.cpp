#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int min(int A, int B, int W) {
    for (int n = 1; n <= 1000000; ++n) {
        if (A * n <= W && B *n >= W) return n;
    }
    return 0;
}
int max(int A, int B, int W) {
    for (int n = 1000000; n >= 1; --n) {
        if (A * n <= W && B *n >= W) return n;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, W;
    cin >> A >> B >> W;
    W *= 1000;
    int mini = min(A, B, W), maxi = max(A, B, W);
    if (mini == 0) {
        cout << "UNSATISFIABLE" << endl;
    } else {
        cout << mini << " " << maxi << endl;
    }

    return 0;
}
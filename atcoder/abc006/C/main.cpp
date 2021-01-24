#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    if (M < 2 * N || 4 * N < M) {
        cout << "-1 -1 -1" << endl;
    } else {
        int K = M - 2 * N;
        int B = K % 2;
        int C = K / 2;
        int A = N - B - C;
        cout << A << " " << B << " " << C << endl;
    }

    return 0;
}
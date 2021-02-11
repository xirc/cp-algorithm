#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, X;
    vector<int> A;

    cin >> N >> X;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int total = 0;
    for (int i = 0; i < N; ++i) {
        if ((X >> i) & 1) {
            total += A[i];
        }
    }
    cout << total << endl;

    return 0;
}
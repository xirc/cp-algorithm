#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int x4 = 0;
    int x2 = 0;
    int x1 = 0;
    for (auto v : A) {
        if (v % 4 == 0) ++x4;
        else if (v % 2 == 1) ++x1;
        else ++x2;
    }

    x2 %= 2;
    if (x1 + x2 <= x4 + 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
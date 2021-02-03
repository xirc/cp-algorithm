#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    int M = 0;
    int S = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 0) continue;
        ++M;
        S += a;
    }
    cout << (S + M - 1) / M << endl;

    return 0;
}
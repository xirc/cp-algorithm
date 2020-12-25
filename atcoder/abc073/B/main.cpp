#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, l, r;
    cin >> N;
    int M = 0;
    for (int i = 0; i < N; ++i) {
        cin >> l >> r;
        int c = r - l + 1;
        M += c;
    }
    cout << M << endl;

    return 0;
}
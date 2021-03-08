#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<string> S;

    cin >> N ;
    S.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            int ox = y;
            int oy = N - 1 - x;
            cout << S[oy][ox];
        }
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S, T;
    cin >> N >> S >> T;
    for (int i = 0; i < N; ++i) {
        cout << S[i] << T[i];
    }
    cout << endl;

    return 0;
}
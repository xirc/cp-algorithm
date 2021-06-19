#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;
    cin >> S >> T;

    int match = 0;
    for (int i = 0 ; i < 3; ++i) {
        if (S[i] == T[i]) ++match;
    }
    cout << match << endl;

    return 0;
}
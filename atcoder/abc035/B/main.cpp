#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    int T;

    cin >> S >> T;
    int x = 0, y = 0;
    int m = 0;
    for (auto c : S) {
        switch (c) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'D': --y; break;
            case 'U': ++y; break;
            case '?': ++m; break;
            default: throw;
        }
    }

    int d = abs(x) + abs(y);
    if (T == 1) {
        d += m;
    } else {
        if (d >= m) d -= m;
        else {
            m -= d;
            m %= 2;
            d = m;
        }
    }
    cout << d << endl;

    return 0;
}
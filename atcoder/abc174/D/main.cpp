#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;

    int ops = 0;
    int l = 0, r = N - 1;
    while (true) {
        while (l < N && S[l] != 'W') ++l;
        while (r >= 0 && S[r] != 'R') --r;
        if (l >= r) break;
        ++ops;
        ++l, --r;
    }
    cout << ops << endl;

    return 0;
}
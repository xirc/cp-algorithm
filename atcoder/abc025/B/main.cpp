#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A, B;
    string s;
    int d;

    int pos = 0;
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> s >> d;
        d = min(max(A, d), B);
        if (s == "East") {
            pos += d;
        } else if (s == "West") {
            pos -= d;
        } else throw;
    }
    if (pos > 0) {
        cout << "East " << pos << endl;
    } else if (pos < 0) {
        cout << "West " << -pos << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
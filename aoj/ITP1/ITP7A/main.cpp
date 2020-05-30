#include <bits/stdc++.h>

using namespace std;

char solve(int m, int f, int r) {
    if (m == -1 || f == -1) {
        return 'F';
    }
    if (m + f >= 80) {
        return 'A';
    }
    if (m + f >= 65) {
        return 'B';
    }
    if (m + f >= 50) {
        return 'C';
    }
    if (m + f >= 30) {
        return r >= 50 ? 'C' : 'D';
    }
    return 'F';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, f, r;
    while (cin >> m >> f >> r, m != -1 || f != -1 || r != -1) {
        cout << solve(m, f, r) << endl;
    }

    return 0;
}
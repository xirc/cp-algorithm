#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> tab(r + 1, vector<int>(c + 1, 0));
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            cin >> tab[y][x];
        }
    }
    // Row Sweep
    for (int y = 0; y < r; ++y) {
        tab[y][c] = accumulate(tab[y].begin(), tab[y].end() - 1, 0, plus<int>());
    }
    // Column Sweep
    for (int x = 0; x < c + 1; ++x) {
        for (int y = 0; y < r; ++y) {
            tab[r][x] += tab[y][x];
        }
    }

    for (int y = 0; y < r + 1; ++y) {
        for (int x = 0; x < c + 1; ++x) {
            if (x > 0) cout << " ";
            cout << tab[y][x];
        }
        cout << endl;
    }

    return 0;
}
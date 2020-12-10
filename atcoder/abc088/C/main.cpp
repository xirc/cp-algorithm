#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> C;

bool solve() {
    for (int i = 0; i < 3; ++i) {
        set<int> S;
        for (int j = 0; j < 3; ++j) {
            S.insert(C[i][j] - C[(i+1)%3][j]);
        }
        if (S.size() > 1) return false;
    }
    for (int j = 0; j < 3; ++j) {
        set<int> S;
        for (int i = 0; i < 3; ++i) {
            S.insert(C[i][j] - C[i][(j+1)%3]);
        }
        if (S.size() > 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    C.assign(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> C[i][j];
        }
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
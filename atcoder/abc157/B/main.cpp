#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> A(3, vector<int>(3, 0));
    vector<vector<bool>> C(3, vector<bool>(3, false));

    auto const mark = [&](int n) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (A[i][j] == n) {
                    C[i][j] = true;
                }
            }
        }
    };
    auto const is_bingo = [&]() {
        bool bingo = false;
        for (int i = 0; i < 3; ++i) {
            bingo |= C[i][0] && C[i][1] && C[i][2];
            bingo |= C[0][i] && C[1][i] && C[2][i];
        }
        bingo |= C[0][0] && C[1][1] && C[2][2];
        bingo |= C[0][2] && C[1][1] && C[2][0];
        return bingo;
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        mark(b);
    }

    cout << (is_bingo() ? "Yes" : "No") << endl;

    return 0;
}
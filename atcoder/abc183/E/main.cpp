#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll solve(int H, int W, vector<vector<char>> const& S) {
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    auto AccL = A, AccU = A, AccLU = A;

    A[0][0] = AccL[0][0] = AccU[0][0] = AccLU[0][0] = 1;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] == '#') continue;
            if (x - 1 >= 0) {
                A[y][x] += AccL[y][x-1];
                A[y][x] %= MOD;
            }
            if (y - 1 >= 0) {
                A[y][x] += AccU[y-1][x];
                A[y][x] %= MOD;
            }
            if (x - 1 >= 0 && y - 1 >= 0) {
                A[y][x] += AccLU[y-1][x-1];
                A[y][x] %= MOD;
            }
            AccL[y][x] = (x - 1 >= 0) ? (AccL[y][x-1] + A[y][x]) : A[y][x];
            AccU[y][x] = (y - 1 >= 0) ? (AccU[y-1][x] + A[y][x]) : A[y][x];
            AccLU[y][x] = (x - 1 >= 0 && y - 1 >= 0) ? (AccLU[y-1][x-1] + A[y][x]) : A[y][x];
            AccL[y][x] %= MOD;
            AccU[y][x] %= MOD;
            AccLU[y][x] %= MOD;
        }
    }
    return A[H-1][W-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int H, W;
    vector<vector<char>> S;
    cin >> H >> W;
    S.assign(H, vector<char>(W, ' '));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> S[y][x];
        }
    }
    cout << solve(H, W, S) << endl;

    return 0;
}
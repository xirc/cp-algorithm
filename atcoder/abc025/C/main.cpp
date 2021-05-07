#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<vector<int>> B(2, vector<int>(3));
vector<vector<int>> C(3, vector<int>(2));
vector<vector<int>> G(3, vector<int>(3));

int score() {
    int score = 0;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            if (y < 2) {
                int sign = G[y][x] == G[y+1][x] ? 1 : -1;
                score += sign * B[y][x];
            }
            if (x < 2) {
                int sign = G[y][x] == G[y][x+1] ? 1 : -1;
                score += sign * C[y][x];
            }
        }
    }
    return score;
}

// O(N!)
int solve(int n) {
    set<int> S;
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            if (G[y][x] != 0) continue;
            if (n % 2 == 0) {
                G[y][x] = 1;
                int s = solve(n+1);
                S.insert(s);
            } else {
                G[y][x] = 2;
                int s = solve(n+1);
                S.insert(s);
            }
            G[y][x] = 0;
        }
    }
    if (S.empty()) {
        return score();
    }
    if (n % 2 == 0) {
        return *S.rbegin();
    } else {
        return *S.begin();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int total_score = 0;
    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < 3; ++x) {
            cin >> B[y][x];
            total_score += B[y][x];
        }
    }
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 2; ++x) {
            cin >> C[y][x];
            total_score += C[y][x];
        }
    }

    int net_score = solve(0);
    int b = (total_score - net_score) / 2;
    int a = total_score - b;
    cout << a << endl;
    cout << b << endl;

    return 0;
}
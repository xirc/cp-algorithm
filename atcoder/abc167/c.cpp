// https://atcoder.jp/contests/abc167/tasks/abc167_c

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int N, M, X;
vector<int> C;
vector<vector<int>> A;

int solverec(int b, int set, vector<int> &S, int total_cost) {
    int ans = numeric_limits<int>::max();
    for (int i = b; i < N; ++i) {
        if ((set >> i) & 1) continue;
        bool satisfy = true;
        for (int j = 0; j < M; ++j) {
            S[j] += A[i][j];
            if (S[j] < X) satisfy = false;
        }
        if (satisfy) {
            ans = min(ans, total_cost + C[i]);
        }
        ans = min(ans, solverec(i + 1, set | (1 << i), S, total_cost + C[i]));

        for (int j = 0; j < M; ++j) {
            S[j] -= A[i][j];
        }
        ans = min(ans, solverec(i + 1, set, S, total_cost));
    }
    return ans;
}

int solve() {
    vector<int> S(M, 0);
    int ans = solverec(0, 0, S, 0);
    if (ans == numeric_limits<int>::max()) {
        return -1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> X;
    C.assign(N, 0);
    A.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}
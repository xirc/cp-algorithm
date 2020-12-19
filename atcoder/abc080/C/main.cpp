#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> F;
vector<vector<int>> P;

int solve() {
    const int M = 1 << 10;
    int max_score = numeric_limits<int>::lowest();
    for (int s = 1; s < M; ++s) {
        bitset<10> state(s);
        int score = 0;
        for (int i = 0; i < N; ++i) {
            int count = 0;
            for (int j = 0; j < 10; ++j) {
                if (state[j] && F[i][j] == 1) ++count;
            }
            score += P[i][count];
        }
        max_score = max(max_score, score);
    }
    return max_score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    F.assign(N, vector<int>(10, 0));
    for (int i =0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> F[i][j];
        }
    }

    P.assign(N, vector<int>(11, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> P[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
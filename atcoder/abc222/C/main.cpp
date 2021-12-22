#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<string> A;

inline bool win(char a, char b) {
    if (a == 'G' && b == 'C') return true;
    if (a == 'C' && b == 'P') return true;
    if (a == 'P' && b == 'G') return true;
    return false;
}

vector<int> solve() {
    vector<array<int,2>> wins(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        wins[i][1] = i;
    }
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i*2 < N; ++i) {
            int a = wins[i*2][1], b = wins[i*2 + 1][1];
            if (win(A[a][j], A[b][j])) {
                wins[i*2][0]++;
            }
            if (win(A[b][j], A[a][j])) {
                wins[i*2+1][0]++;
            }
        }
        sort(wins.begin(), wins.end(), [](auto const& lhs, auto const& rhs) {
            if (lhs[0] != rhs[0]) return lhs[0] > rhs[0];
            return lhs[1] < rhs[1];
        });
    }

    vector<int> order(N);
    for (int i = 0; i < N; ++i) {
        order[i] = wins[i][1];
    }
    return order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    N *= 2;
    A.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    auto ans = solve();
    for (auto x : ans) {
        cout << (x + 1) << endl;
    }


    return 0;
}
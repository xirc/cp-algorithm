#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, Q;
    int Li, Ri;
    int Pi, Qi;
    cin >> N >> M >> Q;

    vector<vector<int>> G(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < M; ++i) {
        cin >> Li >> Ri;
        --Li, --Ri;
        G[0][Ri] +=1;
        G[Li+1][Ri] -= 1;
    }
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            G[i][j] += G[i][j-1];
        }
    }
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            G[j][i] += G[j-1][i];
        }
    }

    for (int i = 0; i < Q; ++i) {
        cin >> Pi >> Qi;
        --Pi, --Qi;
        cout << G[Pi][Qi] << endl;
    }

    return 0;
}
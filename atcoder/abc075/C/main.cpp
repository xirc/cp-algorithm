#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A, B;

// O(M N**3)
int solve() {
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        vector<vector<bool>> G(N, vector<bool>(N, false));
        for (int j = 0; j < M; ++j) {
            int a = A[j], b = B[j];
            G[a][b] = G[b][a] = true;
        }
        int a = A[i], b = B[i];
        G[a][b] = G[b][a] = false;

        for (int k = 0; k < N; ++k) {
            for (int u = 0; u < N; ++u) {
                for (int v = 0; v < N; ++v) {
                    G[u][v] = G[u][v] || (G[u][k] && G[k][v]);
                }
            }
        }
        bool disconnected = false;
        for (int u = 0; u < N; ++u) {
            for (int v = 0; v < N; ++v) {
                if (G[u][v] == false) disconnected = true;
            }
        }
        if (disconnected) ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    cout << solve() << endl;

    return 0;
}
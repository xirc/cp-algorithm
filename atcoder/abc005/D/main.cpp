#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<vector<int>> D;
vector<int> L;

void build() {
    for (int y = 0; y < N + 1; ++y) {
        for (int x = 0; x < N; ++x) {
            D[y][x+1] += D[y][x];
        }
    }
    for (int x = 0; x < N + 1; ++x) {
        for (int y = 0; y < N; ++y) {
            D[y+1][x] += D[y][x];
        }
    }

    L.assign(N * N + 1, 0);
    for (int l = 0; l < N + 1; ++l) {
        for (int r = l + 1; r < N + 1; ++r) {
            for (int b = 0; b < N + 1; ++b) {
                for (int u = b + 1; u < N + 1; ++u) {
                    int p = (u - b) * (r - l);
                    int q = D[u][r] - D[u][l] - D[b][r] + D[b][l];
                    L[p] = max(L[p], q);
                }
            }
        }
    }
    for (int i = 1; i < N * N + 1; ++i) {
        L[i] = max(L[i], L[i-1]);
    }
}

int query(int p) {
    return L[p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    D.assign(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> D[i+1][j+1];
        }
    }

    build();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int p;
        cin >> p;
        cout << query(p) << endl;
    }


    return 0;
}
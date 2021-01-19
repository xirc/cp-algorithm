#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<int> A, B, C, D;

int find(int a, int b) {
    int min_distance = 1e9;
    int min_index = 0;
    for (int i = 0; i < M; ++i) {
        int dist = abs(a - C[i]) + abs(b - D[i]);
        if (dist < min_distance) {
            min_distance = dist;
            min_index = i;
        }
    }
    return min_index;
}

vector<int> solve() {
    vector<int> ans(N, 0);
    for (int i = 0; i < N; ++i) {
        ans[i] = find(A[i], B[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    C.assign(M, 0);
    D.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> C[i] >> D[i];
    }
    auto ans = solve();
    for (auto i : ans) {
        cout << (i + 1) << endl;
    }

    return 0;
}
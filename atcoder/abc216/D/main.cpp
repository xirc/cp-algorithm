#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<deque<int>> A;

bool solve() {
    deque<array<int,2>> S;
    map<int,int> U;

    const auto update = [&](int i) {
        int a = A[i][0];
        if (U[a] > 0) {
            S.push_back({ i, U[a]-1 });
            U[a] = 0;
        } else {
            U[a] = i+1;
        }
    };

    for (int i = 0; i < M;  ++i) {
        assert(A[i].size() > 0);
        update(i);
    }

    int R = 0;
    while (S.size()) {
        auto ij = S.front();
        S.pop_front();
        int i = ij[0], j = ij[1];

        A[i].pop_front();
        if (A[i].size()) update(i);
        A[j].pop_front();
        if (A[j].size()) update(j);

        R += 2;
    }
    return R == 2 * N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, {});
    for (int i = 0; i < M; ++i) {
        int K;
        cin >> K;
        A[i].assign(K, 0);
        for (int j = 0; j < K; ++j) {
            cin >> A[i][j];
        }
    }

    auto ans = solve();
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<array<int,3>> is;

int solve() {
    int U = 0;
    vector<int> T(M+1, 0);
    for (int i = 0; i < N; ++i) {
        U += is[i][2];
        T[is[i][0]] += is[i][2];
        T[is[i][1]+1] -= is[i][2];
    }
    for (int i = 1; i < M + 1; ++i) {
        T[i] += T[i-1];
    }
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        ans = max(ans, U - T[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    is.assign(N, array<int,3>());
    for (int i = 0; i < N; ++i) {
        cin >> is[i][0]
            >> is[i][1]
            >> is[i][2];
        --is[i][0]; --is[i][1];
    }
    cout << solve() << endl;

    return 0;
}
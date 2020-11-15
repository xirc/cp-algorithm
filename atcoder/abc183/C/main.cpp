#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<vector<int>> T;

int solve() {
    vector<int> R;
    for (int i = 1; i < N; ++i) {
        R.push_back(i);
    }
    sort(R.begin(), R.end());

    int ans = 0;
    do {
        int time = T[0][R[0]];
        for (int i = 1; i < N; ++i) {
            time += T[R[i-1]][R[i]];
        }
        time += T[R[N-1]][0];
        if (time == K) ++ans;
    } while (next_permutation(R.begin(), R.end()));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    T.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> T[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}
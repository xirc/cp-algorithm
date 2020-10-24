#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;
vector<int> cost = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

string solve() {
    vector<string> DP(N+1, "");
    for (int i = 0; i < N+1; ++i) {
        if (i != 0 && DP[i] == "") continue;
        for (auto ai : A) {
            int j = i + cost[ai];
            if (j >= N + 1) continue;
            string c = DP[i] + to_string(ai);
            if (c.size() > DP[j].size() || c > DP[j]) {
                DP[j] = c;
            }
        }
    }
    return DP[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
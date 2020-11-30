#include <bits/stdc++.h>

using namespace std;

int solve(int N) {
    vector<int> C;
    C.push_back(1);
    for (int i = 6; i <= N; i *= 6) {
        C.push_back(i);
    }
    for (int i = 9; i <= N; i *= 9) {
        C.push_back(i);
    }

    sort(C.begin(), C.end());
    vector<int> DP(N+1, N);
    DP[0] = 0;
    for (auto s : C) {
        for (int i = 0; i + s <= N; i++) {
            if (DP[i] == N) continue;
            DP[i+s] = min(DP[i+s], DP[i]+1);
        }
    }
    return DP[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}
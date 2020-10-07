#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& D) {
    sort(D.begin(), D.end());
    auto it = unique(D.begin(), D.end());
    return distance(D.begin(), it);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> D;

    cin >> N;
    D.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    cout << solve(N, D) << endl;

    return 0;
}
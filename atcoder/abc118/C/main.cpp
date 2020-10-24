#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int solve() {
    while (true) {
        int mini = *min_element(A.begin(), A.end());
        if (mini == 1) return mini;
        for (int i = 0; i < N; ++i) {
            A[i] -= (A[i] - 1) / mini * mini;
        }
        int mini2 = *min_element(A.begin(), A.end());
        if (mini == mini2) return mini;
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int solve() {
    vector<bool> used(N, false);
    int i = 0;
    int c = 0;

    while (!used[i] && i != 1) {
        used[i] = true;
        i = A[i];
        ++c;
    }

    if (i != 1) {
        return -1;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i]; // 0-indexed
    }
    cout << solve() << endl;

    return 0;
}
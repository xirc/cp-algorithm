#include <bits/stdc++.h>

using namespace std;

vector<int> S, T;

int solve() {
    int count = 0;
    sort(S.begin(), S.end());
    for (int t : T) {
        bool found = binary_search(S.begin(), S.end(), t);
        if (found) count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;

    cin >> N;
    S.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    cin >> Q;
    T.assign(Q, 0);
    for (int i = 0; i < Q; ++i) {
        cin >> T[i];
    }

    cout << solve() << endl;

    return 0;
}
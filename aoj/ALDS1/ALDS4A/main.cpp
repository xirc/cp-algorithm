#include <bits/stdc++.h>

using namespace std;

vector<int> S, T;

int solve() {
    int count = 0;
    for (int t : T) {
        for (int s : S) {
            if (s == t) {
                count++;
                break;
            }
        }
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
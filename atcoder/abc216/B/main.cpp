#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<string> S, T;

    cin >> N;
    S.assign(N, "");
    T.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> T[i];
    }

    bool exists = false;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (S[i] == S[j] && T[i] == T[j]) {
                exists = true;
            }
        }
    }
    cout << (exists ? "Yes" : "No") << endl;

    return 0;
}
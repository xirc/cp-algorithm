#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> M(5);
    for (int i = 0; i < 5; ++i) {
        cin >> M[i];
    }

    vector<int> S;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                int s = M[i] + M[j] + M[k];
                S.push_back(s);
            }
        }
    }

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    reverse(S.begin(), S.end());
    int ans = S[2];
    cout << ans << endl;

    return 0;
}
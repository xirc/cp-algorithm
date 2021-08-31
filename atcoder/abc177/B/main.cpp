#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;
    cin >> S >> T;

    int min_replacement = T.size();
    for (int i = 0; i + T.size() <= S.size(); ++i) {
        int replacement = 0;
        for (int j = 0; j < T.size(); ++j) {
            if (T[j] != S[i+j]) ++replacement;
        }
        min_replacement = min(min_replacement, replacement);
    }
    cout << min_replacement << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    int max_rains = 0;
    int rains = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
        if (S[i] == 'R') {
            ++rains;
            max_rains = max(max_rains, rains);
        } else {
            rains = 0;
        }
    }
    cout << max_rains << endl;

    return 0;
}
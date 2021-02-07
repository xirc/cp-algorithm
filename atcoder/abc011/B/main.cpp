#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << (char)toupper(S[0]);
    for (int i = 1; i < (int)S.size(); ++i) {
        cout << (char)tolower(S[i]);
    }
    cout << endl;

    return 0;
}
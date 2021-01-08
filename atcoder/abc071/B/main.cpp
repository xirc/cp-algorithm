#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    vector<bool> used(26, false);
    for (auto ch : S) {
        int i = (ch - 'a');
        used[i] = true;
    }
    int i;
    for (i = 0; i < 26; ++i) {
        if (used[i]) continue;
        break;
    }
    if (i < 26) {
        cout << char('a' + i) << endl;
    } else {
        cout << "None" << endl;
    }

    return 0;
}
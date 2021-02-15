#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    vector<int> D(6, 0);
    for (auto c : S) {
        int i = c - 'A';
        D[i]++;
    }
    for (int i = 0; i < 6; ++i) {
        if (i > 0) cout << " ";
        cout << D[i];
    }
    cout << endl;

    return 0;
}
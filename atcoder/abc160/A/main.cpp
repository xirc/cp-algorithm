#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    bool similar = S[2] == S[3] && S[4] == S[5];
    cout << (similar ? "Yes" : "No") << endl;

    return 0;
}
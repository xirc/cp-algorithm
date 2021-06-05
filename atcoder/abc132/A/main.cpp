#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    sort(S.begin(), S.end());
    bool pass = (S[0] == S[1] && S[2] == S[3] && S[0] != S[2]);
    cout << (pass ? "Yes" : "No") << endl;

    return 0;
}
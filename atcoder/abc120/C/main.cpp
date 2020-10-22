#include <bits/stdc++.h>

using namespace std;

int solve(string const& S) {
    int zeros = 0, ones = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '0') ++zeros;
        else if (S[i] == '1') ++ ones;
        else throw;
    }
    return min(zeros, ones) * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    cout << solve(S) << endl;

    return 0;
}
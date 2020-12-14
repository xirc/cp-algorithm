#include <bits/stdc++.h>

using namespace std;

bool solve(string const& S, int A, int B) {
    for (int i = 0; i < A + B + 1; ++i) {
        if (i == A) {
            if (S[i] != '-') return false;
        } else {
            if (S[i] < '0' || S[i] > '9') return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    string S;

    cin >> A >> B >> S;
    auto ans = solve(S, A, B) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
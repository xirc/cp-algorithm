#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int const N = S.size();
    bool difficult = true;
    for (int i = 0; i < N; i += 2) {
        if (!islower(S[i])) difficult = false;
    }
    for (int i = 1; i < N; i += 2) {
        if (!isupper(S[i])) difficult = false;
    }
    cout << (difficult ? "Yes" : "No") << endl;

    return 0;
}
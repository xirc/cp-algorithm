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
    bool easy = true;
    for (int i = 0; i < N; i+=2) {
        if (S[i] == 'L') easy = false;
    }
    for (int i = 1; i < N; i+=2) {
        if (S[i] == 'R') easy = false;
    }
    cout << (easy ? "Yes" : "No") << endl;

    return 0;
}
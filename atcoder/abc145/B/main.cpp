#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;

    cin >> N >> S;
    if (N % 2 == 0) {
        bool pass = true;
        for (int i = 0; i * 2 < N; ++i) {
            if (S[i] != S[i+N/2]) {
                pass = false;
                break;
            }
        }
        cout << (pass ? "Yes" : "No") << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
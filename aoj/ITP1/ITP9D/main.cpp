#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "replace") {
            int a, b; string p;
            cin >> a >> b >> p;
            copy(p.begin(), p.end(), S.begin() + a);
        } else if (cmd == "reverse") {
            int a, b;
            cin >> a >> b;
            reverse(S.begin() + a, S.begin() + b + 1);
        } else if (cmd == "print") {
            int a, b;
            cin >> a >> b;
            cout << S.substr(a, b - a + 1) << endl;
        } else throw;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<string> S;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd, key;
        cin >> cmd >> key;
        if (cmd == "insert") {
            S.insert(key);
        } else if (cmd == "find") {
            bool found = S.find(key) != S.end();
            cout << (found ? "yes" : "no") << endl;
        } else throw;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_map<string, int> S;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type, value;
        string key;
        cin >> type;
        if (type == 0) {
            cin >> key >> value;
            S[key] = value;
        } else if (type == 1) {
            cin >> key;
            cout << S[key] << endl;
        } else throw;
    }

    return 0;
}
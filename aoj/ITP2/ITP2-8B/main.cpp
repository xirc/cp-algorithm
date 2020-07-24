#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_map<string, int> M;

    int Q;
    cin >> Q;
    int type, value;
    string key;
    for (int i = 0; i < Q; ++i) {
        cin >> type;
        if (type == 0) {
            // insert key value
            cin >> key >> value;
            M[key] = value;
        } else if (type == 1) {
            // find key
            cin >> key;
            cout << M[key] << endl;
        } else if (type == 2) {
            // erase key
            cin >> key;
            M.erase(key);
        } else throw;
    }

    return 0;
}
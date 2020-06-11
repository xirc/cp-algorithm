#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    list<int> L;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int key;
            cin >> key;
            // O(1)
            L.push_front(key);
        } else if (cmd == "delete") {
            int key;
            cin >> key;
            // O(N)
            auto it = find(L.begin(), L.end(), key);
            if (it != L.end()) {
                L.erase(it);
            }
        } else if (cmd == "deleteFirst") {
            // O(1)
            L.pop_front();
        } else if (cmd == "deleteLast") {
            // O(1)
            L.pop_back();
        } else throw;
    }

    for (auto it = L.begin(); it != L.end(); ++it) {
        if (it != L.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}
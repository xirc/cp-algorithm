#include <bits/stdc++.h>

using namespace std;

int count(const string& s) {
    int move_count = 0;
    list<char> seq(s.begin(), s.end());
    while (true) {
        auto it1 = seq.begin();
        auto it2 = it1; it2++;
        bool moved = false;
        while (it1 !=  seq.end() && it2 != seq.end()) {
            if (*it1 != *it2) {
                seq.erase(it1);
                seq.erase(it2);
                moved = true;
                move_count++;
                break;
            }
            it1++; it2++;
        }
        if (!moved) {
            break;
        }
    }
    return move_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        int cnt = count(s);
        if (cnt % 2 == 1) {
            cout << "DA" << endl;
        } else {
            cout << "NET" << endl;
        }
    }

    return 0;
}
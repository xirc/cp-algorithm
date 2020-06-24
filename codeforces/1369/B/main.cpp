#include <bits/stdc++.h>

using namespace std;

string solve(const string& s) {
    list<char> ss(s.rbegin(), s.rend());
    auto it = ss.begin();
    while (it != ss.end()) {
        if (it != ss.begin()) {
            auto it1 = it;
            it1--;
            if (*it == '1' && *it1 == '0') {
                auto it2 = it1;
                it2--;
                if (it1 == ss.begin() || *it2 != '0') {
                    // Make 0
                    ss.erase(it1);
                    *it = '0';
                } else {
                    // Make 1
                    ss.erase(it1);
                    *it = '1';
                }
                continue;
            }
        }
        it++;
    }
    return string(ss.rbegin(), ss.rend());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        string s;
        cin >> N >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
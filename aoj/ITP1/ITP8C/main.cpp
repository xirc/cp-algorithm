#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<char,int> counter;
    for (string s; cin >> s; !cin.eof()) {
        for (int i = 0; i < s.size(); ++i) {
            char c = tolower(s[i]);
            counter[c]++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        cout << c << " : " << counter[c] << endl;
    }

    return 0;
}
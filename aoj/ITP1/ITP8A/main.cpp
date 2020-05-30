#include <bits/stdc++.h>

using namespace std;

string toggle(const string& in) {
    vector<char> buf(in.size(), ' ');
    for (int i = 0; i < in.size(); ++i) {
        if (islower(in[i])) {
            buf[i] = toupper(in[i]);
        } else {
            buf[i] = tolower(in[i]);
        }
    }
    return string(buf.begin(), buf.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);
    cout << toggle(s) << endl;

    return 0;
}
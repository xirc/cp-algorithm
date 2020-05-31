#include <bits/stdc++.h>

using namespace std;

string tolower(const string& in) {
    vector<char> buf(in.size());
    for (int i = 0; i < in.size(); ++i) {
        buf[i] = tolower(in[i]);
    }
    return string(buf.begin(), buf.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans = 0;
    string w, t;
    cin >> w;
    w = tolower(w);
    while (cin >> t, t != "END_OF_TEXT") {
        t = tolower(t);
        if (w == t) ans++;
    }
    cout << ans << endl;

    return 0;
}
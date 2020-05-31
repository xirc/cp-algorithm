#include <bits/stdc++.h>

using namespace std;

void tolower_inplace(string& in) {
    for (int i = 0; i < in.size(); ++i) {
        in[i] = tolower(in[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans = 0;
    string w, t;
    cin >> w;
    tolower_inplace(w);
    while (cin >> t, t != "END_OF_TEXT") {
        tolower_inplace(t);
        if (w == t) ans++;
    }
    cout << ans << endl;

    return 0;
}
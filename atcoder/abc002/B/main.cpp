#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string vowels = "aiueo";
    string W;
    cin >> W;
    for (auto c: W) {
        if (vowels.find(c) != string::npos) continue;
        cout << c;
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string vowels = "aiueo";
    string W;
    cin >> W;
    auto it = remove_if(W.begin(), W.end(), [&](const auto c) {
        return vowels.find(c) != string::npos;
    });
    W.erase(it, W.end());
    cout << W << endl;

    return 0;
}
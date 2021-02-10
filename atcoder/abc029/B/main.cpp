#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int count = 0;
    for (int i = 0; i < 12; ++i) {
        string S;
        cin >> S;
        auto it = find_if(S.begin(), S.end(), [](const auto c) { return c == 'r'; });
        if (it != S.end()) ++count;
    }
    cout << count << endl;

    return 0;
}
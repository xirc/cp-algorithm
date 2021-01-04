#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int count = 0;
    for (auto c : S) {
        if (c == '1') ++count;
    }
    cout << count << endl;

    return 0;
}
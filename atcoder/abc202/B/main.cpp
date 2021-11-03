#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    for (auto &c : S) {
        if (c == '6') c = '9';
        else if (c == '9') c= '6';
    }
    cout << S << endl;

    return 0;
}
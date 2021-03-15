#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> S(3, 0);
    cin >> S[0] >> S[1] >> S[2];

    int count = 0;
    while (true) {
        if (S[0] == S[1] && S[1] == S[2]) break;
        sort(S.begin(), S.end());
        if (S[0] == S[1]) {
            ++S[0], ++S[1];
        } else {
            S[0] += 2;
        }
        ++count;
    }
    cout << count << endl;

    return 0;
}
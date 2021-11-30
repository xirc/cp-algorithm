#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string> S(3, "");
    string T;
    
    cin >> S[0] >> S[1] >> S[2];
    cin >> T;

    for (auto c : T) {
        int i = c - '1';
        cout << S[i];
    }
    cout << endl;

    return 0;
}
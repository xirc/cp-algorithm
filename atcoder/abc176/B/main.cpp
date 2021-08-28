#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < (int)N.size(); ++i) {
        int d = N[i] - '0';
        sum += d;
    }
    bool x9 = (sum % 9) == 0;
    cout << (x9 ? "Yes" : "No") << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string A, B;
    cin >> A >> B;
    if (A.size() > B.size()) {
        cout << A << endl;
    } else {
        cout << B << endl;
    }

    return 0;
}
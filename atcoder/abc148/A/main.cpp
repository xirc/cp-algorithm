#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    vector<bool> ans(3, true);
    ans[A-1] = false;
    ans[B-1] = false;
    for (int i = 0; i < 3; ++i) {
        if (ans[i]) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
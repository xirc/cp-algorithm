#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<array<int, 2>> BA;

    cin >> N;
    BA.assign(N, { 0 ,0 });
    for (auto &ba : BA) {
        cin >> ba[1] >> ba[0];
    }

    sort(BA.begin(), BA.end());
    bool fail = false;
    int t = 0;
    for (auto &ba : BA) {
        t += ba[1];
        if (t > ba[0]) {
            fail = true;
            break;
        }
    }
    cout << (fail ? "No" : "Yes") << endl;

    return 0;
}
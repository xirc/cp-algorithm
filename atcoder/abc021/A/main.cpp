#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    int b = 1;
    vector<int> bs;
    cin >> N;
    while (N > 0) {
        if (N & 1) {
            bs.push_back(b);
        }
        N >>= 1;
        b <<= 1;
    }
    cout << bs.size() << endl;
    for (auto v : bs) {
        cout << v << endl;
    }

    return 0;
}
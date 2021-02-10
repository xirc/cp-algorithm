#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c = 0;
    for (int i = 0; i < 10000; ++i) {
        int j = i;
        while (j > 0) {
            c += j % 10 == 1 ? 1 : 0;
            j /= 10;
        }
        cout << c << endl;
    }

    return 0;
}
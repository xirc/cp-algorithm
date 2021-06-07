#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int L, R;
    cin >> L >> R;

    int mini = 2018;
    for (int i = L; i <= min(L + 2018, R); ++i) {
        for (int j = i + 1; j <= min(i + 2018, R); ++j) {
            int a = i % 2019, b = j % 2019;
            mini = min(mini, (a * b) % 2019);
        }
    }
    cout << mini << endl;

    return 0;
}
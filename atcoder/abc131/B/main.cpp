#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, L;
    cin >> N >> L;
    int min = 0;
    int absmin = 400;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += L + i;
        if (absmin > abs(L + i)) {
            absmin = abs(L + i);
            min = L + i;
        }
    }
    cout << sum - min << endl;

    return 0;
}
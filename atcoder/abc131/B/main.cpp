#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, L;
    cin >> N >> L;

    int R = L + N - 1;
    int absmin;
    if (L > 0) absmin = L;
    else if (R < 0) absmin = R;
    else absmin = 0;
    
    int sum = (L + R) * N / 2 - absmin;
    cout << sum << endl;

    return 0;
}
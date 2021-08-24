#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    N %= 1000;
    if (N > 0) N = 1000 - N;
    cout << N << endl;

    return 0;
}
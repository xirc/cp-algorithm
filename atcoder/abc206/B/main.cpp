#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    ll cash = 0;
    int i;
    for (i = 1; cash < N; ++i) {
        cash += i;
    }
    cout << (i-1) << endl;

    return 0;
}
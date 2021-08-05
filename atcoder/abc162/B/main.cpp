#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    ll fizzbuzz = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 3 != 0 && i % 5 != 0) {
            fizzbuzz += i;
        }
    }
    cout << fizzbuzz << endl;

    return 0;
}
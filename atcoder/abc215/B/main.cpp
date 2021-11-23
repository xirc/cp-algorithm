#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    int k = 0;
    ll a = 1;
    while (a * 2 <= N) {
        a *= 2;
        k++;
    }
    cout << k << endl;

    return 0;
}
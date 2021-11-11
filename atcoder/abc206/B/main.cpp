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
    int i = 1;
    while (true) {
        cash += i;
        if (cash >= N) {
            break;
        }
        ++i;
    }
    cout << i << endl;

    return 0;
}
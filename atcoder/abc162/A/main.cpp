#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    bool contains = false;
    while (N > 0) {
        if (N % 10 == 7) contains = true;
        N /= 10;
    }
    cout << (contains ? "Yes" : "No") << endl;

    return 0;
}
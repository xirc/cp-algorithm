#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;

    cin >> n;
    cout << (n & 1 ? n + 1 : n - 1) << endl;

    return 0;
}
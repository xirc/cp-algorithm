#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M, D;
    cin >> M >> D;
    cout << (M % D == 0 ? "YES" : "NO") << endl;

    return 0;
}
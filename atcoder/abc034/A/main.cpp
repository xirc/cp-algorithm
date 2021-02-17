#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> x >> y;
    assert(x != y);
    cout << (x < y ? "Better" : "Worse") << endl;

    return 0;
}
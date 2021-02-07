#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    int X;
    int c = 0;
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == X) continue;
        if (c > 0) cout << " ";
        cout << a;
        ++c;
    }
    cout << endl;

    return 0;
}
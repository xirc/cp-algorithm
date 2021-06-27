#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    int h;
    int count = 0;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> h;
        if (h >= K) ++count;
    }
    cout << count << endl;

    return 0;
}
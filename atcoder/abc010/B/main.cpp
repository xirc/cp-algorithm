#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    for (int a : A) {
        if (a == 1) continue;
        else if (a == 2) ans += 1;
        else {
            int b;
            for (b = a; b > 2; --b) {
                if ((b - 2) % 2 == 0) continue;
                if ((b - 2) % 3 == 0) continue;
                break;
            }
            ans += (a - b);
        }
    }
    cout << ans << endl;

    return 0;
}
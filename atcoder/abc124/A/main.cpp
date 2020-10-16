#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    int ans = 0;
    if (A == B) {
        ans += 2 * A;
    } else {
        int C = max(A, B);
        ans += C + C - 1;
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, T;
    cin >> A >> B >> T;

    int sum = 0;
    for (int tt = A; tt < T + 1; tt += A) {
        sum += B;
    }
    cout << sum << endl;

    return 0;
}
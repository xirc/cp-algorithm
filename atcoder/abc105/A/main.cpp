#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    if (N % K == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    if (N % 2 == 0) {
        cout << N << endl;
    } else {
        cout << (N * 2) << endl;
    }

    return 0;
}
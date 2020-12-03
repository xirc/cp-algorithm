#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A;
    cin >> N >> A;

    N %= 500;
    if (N <= A) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
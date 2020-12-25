#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    if (N % 10 == 9 || N / 10 % 10 == 9) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
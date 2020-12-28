#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    int b = 1;
    while (b * 2 <= N) {
        b *= 2;
    }
    cout << b << endl;

    return 0;
}
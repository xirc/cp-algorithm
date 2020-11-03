#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int i = 111; i < 1000; i += 111) {
        if (N > i) continue;
        cout << i << endl;
        break;
    }

    return 0;
}
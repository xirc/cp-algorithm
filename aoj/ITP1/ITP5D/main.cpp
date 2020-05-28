#include <bits/stdc++.h>

using namespace std;

void solve(int N) {
    for (int i = 1; i <= N; ++i) {
        int x = i;
        if (x % 3 == 0) {
            cout << " " << i;
            continue;
        }
        do {
            if (x % 10 == 3) {
                cout << " " << i;
                break;
            }
            x /= 10;
        } while (x);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    solve(N);

    return 0;
}
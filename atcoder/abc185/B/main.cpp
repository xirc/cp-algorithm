#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, T;
    cin >> N >> M >> T;

    bool success = true;
    int time = 0;
    int remaining = N;
    for (int mm = 0; mm < M; ++mm) {
        int A, B;
        cin >> A >> B;
        int consumed = A - time;
        remaining -= consumed;
        if (remaining <= 0) {
            success = false;
            break;
        }
        int charged = B - A;
        remaining += charged;
        remaining = min(remaining, N);
        time = B;
    }
    int consumed = T - time;
    remaining -= consumed;
    if (remaining <= 0) success = false;

    cout << (success ? "Yes" : "No") << endl;

    return 0;
}
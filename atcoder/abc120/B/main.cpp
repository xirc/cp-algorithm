#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B, int K) {
    for (int i = 100; i > 0; --i) {
        if (A % i == 0 && B % i == 0) {
            --K;
            if (K == 0) return i;
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, K;
    cin >> A >> B >> K;
    cout << solve(A, B, K)<< endl;

    return 0;
}
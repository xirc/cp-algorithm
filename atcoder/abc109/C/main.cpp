#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> xs;

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int solve() {
    int D = 0;
    for (int i = 0; i < N; ++i) {
        D = gcd(D, abs(xs[i] - X));
    }
    return D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> X;
    xs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i];
    }
    cout << solve() << endl;

    return 0;
}
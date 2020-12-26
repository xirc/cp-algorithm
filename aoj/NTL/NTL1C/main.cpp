#include <bits/stdc++.h>

inline unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

inline unsigned long long lcm(unsigned long long a, unsigned long long b) {
    if (a == 0 && b == 0) return 0;
    return a / gcd(a, b) * b;
}


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long ans = 1;
    for (int i = 0; i < N; ++i) {
        ans = lcm(ans, A[i]);
    }
    cout << ans << endl;

    return 0;
}
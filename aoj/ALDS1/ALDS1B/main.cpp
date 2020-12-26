#include <bits/stdc++.h>

inline unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}
#include <bits/stdc++.h>

// GCD (a,b)
// Time: O( log(min(a,b) )
long long gcd(long long a, long long b) {
    while (b > 0) {
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
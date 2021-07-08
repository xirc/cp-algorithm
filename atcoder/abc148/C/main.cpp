#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int gcd(int a, int b) {
    while (b > 0) {
        int t = a % b;
        a = b, b = t;
    }
    return a;
}

ll lcm(int a, int b) {
    return ll(a) / gcd(a,b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    cout << lcm(A, B) << endl;

    return 0;
}
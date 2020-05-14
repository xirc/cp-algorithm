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

// LCM (a,b)
// Time: O( log(min(a,b)) )
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}


#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        long long A, B;
        cin >> A >> B;
        cout << gcd(A,B) << " " << lcm(A,B) << endl;
    }

    return 0;
}
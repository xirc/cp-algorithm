#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    int low = A * 1, high = A * 6;
    bool ans = (B >= low && B <= high);
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
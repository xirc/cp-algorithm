#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, A, B;

int digsum(int m) {
    int s = 0;
    while (m > 0) {
        s += m % 10;
        m /= 10;
    }
    return s;
}

int solve() {
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        int ds = digsum(i);
        if (ds >= A && ds <= B) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;


int f(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

bool solve(int N) {
    auto S = f(N);
    return N % S == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    auto ans = solve(N) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
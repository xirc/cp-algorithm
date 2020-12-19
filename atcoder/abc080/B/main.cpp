#include <bits/stdc++.h>

using namespace std;

int fx(int N) {
    int value = 0;
    while(N > 0) {
        value += (N % 10);
        N /= 10;
    }
    return value;
}

bool solve(int N) {
    return N % fx(N) == 0;
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
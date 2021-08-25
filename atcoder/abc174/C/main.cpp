#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int K) {
    unordered_set<int> seen;
    int i = 1;
    int N = 7 % K;
    while (seen.count(N) == 0) {
        if (N == 0) {
            return i;
        }
        seen.insert(N);
        N = (N * 10 + 7) % K;
        ++i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;
    cout << solve(K) << endl;

    return 0;
}
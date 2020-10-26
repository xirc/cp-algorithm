#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    if (n & 1) return 3 * n + 1;
    else return n / 2;
}

int solve(int s) {
    unordered_set<int> A;

    int i = 1;
    int ai = s;
    while (A.count(ai) == 0) {
        A.insert(ai);
        ai = f(ai);
        ++i;
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}
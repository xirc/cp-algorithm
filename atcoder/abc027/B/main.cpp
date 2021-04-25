#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;

int solve() {
    int M = accumulate(A.begin(), A.end(), 0, plus<int>());
    if (M % N != 0) return -1;
    M /= N;

    int ans = 0;
    int acc = 0;
    for (auto ai : A) {
        acc += ai - M;
        if (acc != 0) ans += 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &ai : A) cin >> ai;
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &ai : A) cin >> ai;

    int ans = 200 * 200 * 100;
    int sum = accumulate(A.begin(), A.end(), 0, plus<int>());
    int avg1 = sum / N;
    int avg2 = (sum + N - 1) / N;
    ans = min(ans, accumulate(A.begin(), A.end(), 0, [&](auto acc, auto v) {
        return acc + (v - avg1) * (v - avg1);
    }));
    ans = min(ans, accumulate(A.begin(), A.end(), 0, [&](auto acc, auto v) {
        return acc + (v - avg2) * (v - avg2);
    }));
    cout << ans << endl;

    return 0;
}
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
    for (auto &a : A) cin >> a;

    int ans = 0;
    int i = 1;
    auto it = A.begin();
    while (it != A.end()) {
        while (it != A.end() && *it != i) {
            ++it; ++ans;
        }
        if (it == A.end()) break;
        ++it, ++i;
    }
    cout << (ans == N ? -1 : ans) << endl;

    return 0;
}
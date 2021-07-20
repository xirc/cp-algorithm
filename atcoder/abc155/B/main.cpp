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

    bool pass = true;
    for (auto a : A) {
        if (a % 2 != 0) continue;
        if (a % 3 == 0) continue;
        if (a % 5 == 0) continue;
        pass = false;
    }
    cout << (pass ? "APPROVED" : "DENIED") << endl;

    return 0;
}
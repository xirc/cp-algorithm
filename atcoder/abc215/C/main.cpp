#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    string S;
    cin >> S >> K;

    sort(S.begin(), S.end());
    for (int i = 0; i < K - 1; ++i) {
        next_permutation(S.begin(), S.end());
    }
    cout << S << endl;

    return 0;
}
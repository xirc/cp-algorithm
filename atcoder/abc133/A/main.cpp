#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, A, B;
    cin >> N >> A >> B;
    int C = min(N * A, B);
    cout << C << endl;

    return 0;
}
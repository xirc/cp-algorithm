#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;
    int odd = (N+1) / 2;
    auto probability = ff(odd) / N;
    cout << fixed << setprecision(7) << probability << endl;

    return 0;
}
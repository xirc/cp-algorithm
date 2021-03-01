#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int candies = 0;
    for (int i = 1; i <= N; ++i) {
        candies += i;
    }
    cout << candies << endl;

    return 0;
}
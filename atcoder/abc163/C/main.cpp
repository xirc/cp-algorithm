#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> sub;

    cin >> N;
    sub.assign(N, 0);
    for (int i = 1; i < N; ++i) {
        int a;
        cin >> a;
        --a;
        sub[a]++;
    }
    for (int i = 0; i < N; ++i) {
        cout << sub[i] << endl;
    }

    return 0;
}
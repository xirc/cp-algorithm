#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;
    vector<int> Q(N, 0);
    for (int i = 0; i < N; ++i) {
        int pi;
        cin >> pi;
        --pi;
        Q[pi] = (i+1);
    }
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << Q[i];
    }
    cout << endl;

    return 0;
}
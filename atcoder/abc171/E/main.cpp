#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int S = 0;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S ^= A[i];
    }
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << (S ^ A[i]);
    }
    cout << endl;

    return 0;
}
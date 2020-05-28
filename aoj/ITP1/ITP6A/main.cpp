#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (i < N - 1) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // O(QN)
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int b, e, k;
        cin >> b >> e >> k;
        int count = count_if(A.begin() + b, A.begin() + e, [&](int val) { return val == k; });
        cout << count << endl;
    }

    return 0;
}
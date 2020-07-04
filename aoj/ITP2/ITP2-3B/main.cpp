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

    // O(NQ)
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int type, b, e;
        cin >> type >> b >> e;
        if (type == 0) {
            //min
            auto mini = *min_element(A.begin() + b, A.begin() + e);
            cout << mini << endl;
        } else if (type == 1) {
            //max
            auto maxi = *max_element(A.begin() + b, A.begin() + e);
            cout << maxi << endl;
        } else throw;
    }

    return 0;
}
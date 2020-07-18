#include <bits/stdc++.h>

using namespace std;

// Don't use std::equal_range, std::lower_bound, std::upper_bound for practice!
int lower_bound(const vector<int>& A, int value) {
    int l = 0, r = A.size();
    while (l < r) {
        const int m = (l + r) >> 1;
        if (A[m] >= value) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
int upper_bound(const vector<int>& A, int value) {
    int l = 0, r = A.size();
    while (l < r) {
        const int m = (l + r) >> 1;
        if (A[m] <= value) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}
pair<int,int> equal_range(const vector<int>& A, int value) {
    return { lower_bound(A, value), upper_bound(A, value) };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int k;
        cin >> k;
        auto r = equal_range(A, k);
        cout << r.first << " " << r.second << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

void dump() {
    for (int i = 0; i < A.size(); ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void solve() {
    dump();
    for (int i = 1; i < A.size(); ++i) {
        auto key = A[i];
        int j = i -1;
        for (; j >= 0 && A[j] > key; --j) {
            A[j+1] = A[j];
        }
        A[j+1] = key;
        dump();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    solve();

    return 0;
}
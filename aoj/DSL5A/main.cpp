#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int T;
vector<int> L, R;
vector<int> A;

int solve() {
    A.assign(T, 0);

    for (int i = 0; i < N; ++i) {
        int l = L[i], r = R[i];
        A[l]++;
        A[r]--;
    }
    int ans = A[0];
    for (int i = 1; i < T; ++i) {
        A[i] += A[i-1];
        ans = max(ans, A[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    L.assign(N, 0);
    R.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
    }
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& A) {
    int mini = *min_element(A.begin(), A.end());

    vector<int> fixedValue;
    vector<int> fixedIndex;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] % mini != 0) {
            fixedValue.push_back(A[i]);
            fixedIndex.push_back(i);
        }
    }
    for (int i = 1; i < fixedValue.size(); ++i) {
        if (fixedValue[i] < fixedValue[i-1]) {
            return false;
        }
    }

    vector<int> inout(fixedIndex.size() + 1);
    for (int i = 0; i < A.size(); ++i) {
        if (binary_search(fixedIndex.begin(), fixedIndex.end(), i)) continue;
        auto vit = upper_bound(fixedValue.begin(), fixedValue.end(), A[i]);
        int vi = distance(fixedValue.begin(), vit);
        auto iit = upper_bound(fixedIndex.begin(), fixedIndex.end(), i);
        int ii = distance(fixedIndex.begin(), iit);
        inout[vi]++;
        inout[ii]--;
    }
    for (int i = 0; i < inout.size(); ++i) {
        if (inout[i] != 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    vector<int> A;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        auto ans = solve(A) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}
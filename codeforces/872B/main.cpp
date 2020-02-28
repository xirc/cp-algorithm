// http://codeforces.com/problemset/problem/872/B

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
vector<int> A;

// O(N logN)
int solve() {
    if (K == 1) {
        return *min_element(A.begin(), A.end());
    }
    if (K >= 3) {
        return *max_element(A.begin(), A.end());
    }

    multiset<int> L, R;
    L.insert(A[0]);
    for (int i = 1; i < N; ++i) {
        R.insert(A[i]);
    }

    int ans = max(*L.begin(), *R.begin());
    for (int i = 1; i < N - 1; ++i) {
        L.insert(A[i]);
        R.erase(R.find(A[i]));
        ans = max(ans, *L.begin());
        ans = max(ans, *R.begin());
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

int solve() {
    int mini = *min_element(A.begin(), A.end());
    int maxi = *max_element(A.begin(), A.end());
    return maxi - mini;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
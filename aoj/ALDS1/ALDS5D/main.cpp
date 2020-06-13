#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9+1;
ll merge(vector<int>& A, int l, int m, int r) {
    ll count = 0;
    const int n1 = m - l;
    const int n2 = r - m;
    vector<int> L(n1 + 1), R(n2 + 1);
    copy(A.begin() + l, A.begin() + m, L.begin());
    copy(A.begin() + m, A.begin() + r, R.begin());
    L[n1] = inf;
    R[n2] = inf;
    int i = 0, j = 0;
    for (int k = l; k < r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            count += (n1 - i);
            A[k] = R[j];
            j++;
        }
    }
    return count;
}

ll merge_sort(vector<int>& A, int l, int r) {
    if (r - l <= 1) return 0;
    ll count = 0;
    int m = (l + r) / 2;
    count += merge_sort(A, l, m);
    count += merge_sort(A, m, r);
    count += merge(A, l, m, r);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    ll ans = merge_sort(A, 0, N);
    cout << ans << endl;

    return 0;
}
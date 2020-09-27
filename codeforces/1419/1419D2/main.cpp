#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& A) {
    const int N = A.size();

    auto B = A;
    sort(B.begin(), B.end());

    int j = N - 1;
    for (int i = 0; i < N; i+=2) {
        A[i] = B[j];
        --j;
    }
    if (N % 2 == 0) {
        A[N-1] = B[j];
        --j;
    }

    int ans = 0;
    int l = 1, r = N - 2 - (N % 2 == 0 ? 1 : 0);
    for (; j >= 0; --j) {
        if (B[j] < A[l-1] && B[j] < A[l+1]) {
            A[l] = B[j];
            l += 2;
            ++ans;
        } else {
            A[r] = B[j];
            r -= 2;
        }
    }
    return ans;
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
    auto ans = solve(A);
    cout << ans << endl;
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
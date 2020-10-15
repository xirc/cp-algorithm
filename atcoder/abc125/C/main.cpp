#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int solve(int N, vector<int>& A) {
    vector<int> L(N, 0);
    vector<int> R(N, 0);

    L[0] = A[0];
    for (int i = 1; i < N; ++i) {
        L[i] = gcd(L[i-1], A[i]);
    }
    R[N-1] = A[N-1];
    for (int i = N-2; i >= 0; --i) {
        R[i] = gcd(R[i+1], A[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int gl = i > 0 ? L[i-1] : 0;
        int gr = i < N - 1 ? R[i+1] : 0;
        int g = gcd(gl, gr);
        ans = max(ans, g);
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
    cout << solve(N, A) << endl;

    return 0;
}
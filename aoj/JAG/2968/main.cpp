#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int na = b, nb = a % b;
        a = na, b = nb;
    }
    return a;
}

// O(N^2)
long long solve(const vector<int>& A) {
    const int N = A.size();
    long long ans = 0;
    vector<unordered_map<int,long long>> DP(N+1, unordered_map<int,long long>());
    for (int i = 0; i < N; ++i) {
        if (A[i] > 1) {
            DP[i+1][A[i]] = max(DP[i+1][A[i]], (long long)A[i]);
            ans = max(ans, DP[i+1][A[i]]);
        }
        for (auto const &kv : DP[i]) {
            int g = gcd(kv.first, A[i]);
            DP[i+1][kv.first] = max(DP[i+1][kv.first], kv.second);
            if (g > 1) {
                DP[i+1][g] = max(DP[i+1][g], kv.second + A[i]);
                ans = max(ans, DP[i+1][g]);
            }
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
    cout << solve(A) << endl;

    return 0;
}

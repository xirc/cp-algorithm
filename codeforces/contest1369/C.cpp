#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int>& A, vector<int>& W) {
    int N = A.size(), K = W.size();
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(W.begin(), W.end());

    long long ans = 0;
    auto it = A.begin();
    for (int i = 0; i < K; ++i) {
        auto w = W[i];
        if (w == 1) {
            ans += (long long) 2 * (*it);
            it++;
        } else {
            ans += *it;
            it++;
        }
    }
    for (int i = 0; i < K; ++i) {
        auto w = W[i];
        if (w == 1) continue;
        for (int j = 0; j < w - 2; ++j) {
            it++;
        }
        ans += *it;
        ++it;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int N, K;
        scanf("%d %d", &N, &K);
        vector<int> A(N), W(K);
        for (int j = 0; j < N; ++j) {
            scanf("%d", &A[j]);
        }
        for (int j = 0; j < K; ++j) {
            scanf("%d", &W[j]);
        }
        auto ans = solve(A, W);
        printf("%lld\n", ans);
    }

    return 0;
}
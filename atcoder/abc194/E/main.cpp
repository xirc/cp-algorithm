#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A(N);
int solve() {
    set<int> S;
    for (int i = 0; i <= N; ++i) {
        S.insert(i);
    }

    vector<int> C(N, 0);
    for (int i = 0; i < M; ++i) {
        C[A[i]]++;
        S.erase(A[i]);
    }

    int ans = *S.begin();
    for (int i = M; i < N; ++i) {
        C[A[i-M]]--;
        if (C[A[i-M]] == 0) {
            S.insert(A[i-M]);
        }
        C[A[i]]++;
        S.erase(A[i]);
        ans = min(ans, *S.begin());
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    for (auto &a : A) {
        cin >> a;
    }
    cout << solve() << endl;

    return 0;
}
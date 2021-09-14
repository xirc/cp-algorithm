#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A;

int solve() {
    A.push_back(0);
    A.push_back(N + 1);
    sort(A.begin(), A.end());

    int w = N;
    for (int i = 0; i + 1 < A.size(); ++i) {
        int space = A[i+1] - A[i] - 1;
        if (space > 0) {
            w = min(w, space);
        }
    }

    int ans = 0;
    for (int i = 0; i + 1 < A.size(); ++i) {
        int space = A[i+1] - A[i] - 1;
        ans += (space + w - 1) / w;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(M, 0);
    for (auto &a : A) cin >> a;
    cout << solve() << endl;

    return 0;
}
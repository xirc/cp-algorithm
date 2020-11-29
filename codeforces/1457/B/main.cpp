#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> C;

int count(vector<int> A, int color) {
    int ans = 0;
    int i = 0;
    while (i < N) {
        if (A[i] == color) {
            ++i;
            continue;
        }
        ++ans;
        for (int j = 0; j < K && i + j < N; ++j) {
            A[i+j] = color;
        }
        i += K;
    }
    return ans;
}

int solve() {
    int ans = N;
    for (int color = 0; color < 100; ++color) {
        ans = min(ans, count(C, color));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        C.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
            --C[i];
        }
        cout << solve() << endl;
    }

    return 0;
}
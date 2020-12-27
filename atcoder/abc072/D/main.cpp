#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> P;

int solve() {
    int ans = 0;
    for (int i = 0; i + 1 < N; ++i) {
        if (P[i] == i) {
            swap(P[i], P[i+1]);
            ++ans;
        }
    }
    if (P[N-1] == N-1) {
        swap(P[N-2], P[N-1]);
        ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    P.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];
    }
    cout << solve() << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long ans = 0;
    vector<int> count(1e5+1);
    for (int i = 0; i < N; ++i) {
        ans += A[i];
        count[A[i]]++;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int B, C;
        cin >> B >> C;
        ans -= (long long) B * count[B];
        ans += (long long) C * count[B];
        count[C] += count[B];
        count[B] = 0;
        cout << ans << endl;
    }

    return 0;
}
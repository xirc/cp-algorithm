#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int solve() {
    int i = 0;
    int ans = 0;
    for (int k = 2; k < 1001; ++k) {
        int gcdc = 0;
        for (auto v : A) {
            if (v % k == 0) gcdc++;
        }
        if (ans < gcdc) {
            i = k;
            ans = max(ans, gcdc);
        }
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
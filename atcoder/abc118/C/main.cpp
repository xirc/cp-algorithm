#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int gcd(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int solve() {
    assert(N > 0);
    int ans = A[0];
    for (int i = 0; i < N; ++i) {
        ans = gcd(ans, A[i]);
    }
    return ans;
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
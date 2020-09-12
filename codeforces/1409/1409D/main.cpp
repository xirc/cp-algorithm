#include <bits/stdc++.h>

using namespace std;

long long solve(long long N, int S) {
    int ss = 0;
    vector<int> A;
    while (N > 0) {
        int digit = N % 10;
        ss += digit;
        A.push_back(digit);
        N /= 10;
    }

    long long base = 1;
    long long ans = 0;
    for (int i = 0; i < A.size() && ss > S; ++i, base *= 10) {
        if (A[i] == 0) continue;
        ans += (10 - A[i]) * base;
        ss -= A[i];
        A[i] = 0;
        if (i + 1 < A.size()) {
            ++A[i+1];
            ++ss;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, S;
    long long N;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> S;
        cout << solve(N, S) << endl;
    }

    return 0;
}
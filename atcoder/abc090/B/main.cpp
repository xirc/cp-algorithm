#include <bits/stdc++.h>

using namespace std;

int A, B;

bool is_palindrome(int N) {
    vector<int> ds;
    while (N > 0) {
        ds.push_back(N % 10);
        N /= 10;
    }
    const int M = ds.size();
    for (int i = 0; i < M; ++i) {
        if (ds[i] != ds[M-1-i]) return false;
    }
    return true;
}

int solve() {
    int ans = 0;
    for (int i = A; i <= B; ++i) {
        if (is_palindrome(i)) ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;
    cout << solve() << endl;

    return 0;
}
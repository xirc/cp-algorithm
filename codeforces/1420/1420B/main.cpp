#include <bits/stdc++.h>

using namespace std;

int highest_one_bit(int N) {
    // It can be imporved, but it is enough.
    assert(N >= 0);
    for (int i = 30; i >= 0; --i) {
        if ((N >> i) & 1) return i;
    }
    return -1;
}

// O(N)
long long solve(vector<int> const& A) {
    long long ans = 0;
    unordered_map<int,int> M;
    for (auto v : A) {
        int h = highest_one_bit(v);
        ans += M[h];
        ++M[h];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(A) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

int solve() {
    unordered_map<int,int> mp;
    for (auto a : A) {
        ++mp[a];
    }

    int ans = N;
    int m = 0;
    for (auto e : mp) {
        auto c = e.second;
        int r = (c - 1) % 2 + 1;
        ans -= (c - r);
        if (r == 2) ++m;
    }
    if (m % 2 == 0) {
        ans -= m;
    } else {
        ans -= m + 1;
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
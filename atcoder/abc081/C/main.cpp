#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;
vector<int> A;

int solve() {
    map<int,int> mp;
    for (auto a : A) {
        ++mp[a];
    }
    vector<vector<int>> hs;
    for (auto e : mp) {
        hs.push_back({ e.second, e.first });
    }
    int L = max(0, (int)hs.size() - K);
    sort(hs.begin(), hs.end());
    int ans = 0;
    for (int i = 0; i < L; ++i) {
        ans += hs[i][0];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
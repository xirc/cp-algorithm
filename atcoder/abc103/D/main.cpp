#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int,int>> AB;

int solve() {
    sort(AB.begin(), AB.end());

    int ans = 0;
    int e = AB[0].second;
    for (int i = 1; i < M; ++i) {
        auto a = AB[i].first, b = AB[i].second;
        if (a < e) {
            e = min(e, b);
        } else {
            ++ans;
            e = b;
        }
    }
    ++ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    AB.assign(M, {});
    for (int i = 0; i < M; ++i) {
        cin >> AB[i].first >> AB[i].second;
    }
    cout << solve() << endl;

    return 0;
}
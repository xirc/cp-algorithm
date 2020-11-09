#include <bits/stdc++.h>

using namespace std;

pair<int,int> A, B;

vector<pair<int,int>> solve() {
    int dx = B.first - A.first;
    int dy = B.second - A.second;
    auto C = make_pair(B.first - dy, B.second + dx);
    auto D = make_pair(C.first - dx, C.second - dy);
    return { C, D };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    auto ans = solve();
    cout << ans[0].first << " " << ans[0].second << " " << ans[1].first << " " << ans[1].second << endl;

    return 0;
}
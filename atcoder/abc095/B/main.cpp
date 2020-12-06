#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> ms;

int solve() {
    int ans = 0;
    int xx = accumulate(ms.begin(), ms.end(), 0, plus<int>());
    ans += N;
    X -= xx;
    int mx = *min_element(ms.begin(), ms.end());
    ans += (X / mx);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> X;
    ms.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> ms[i];
    }
    cout << solve() << endl;

    return 0;
}
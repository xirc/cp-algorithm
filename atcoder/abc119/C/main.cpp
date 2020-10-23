#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;
int N, A, B, C;
vector<int> L;

int solve(int i, int aa, int bb, int cc) {
    if (i == N) {
        if (min({ aa, bb, cc }) == 0) {
            return inf;
        }
        return abs(A - aa) + abs(B - bb) + abs(C - cc) - 30;
    }

    int ans0 = solve(i + 1, aa, bb, cc);
    int ans1 = solve(i + 1, aa + L[i], bb, cc) + 10;
    int ans2 = solve(i + 1, aa, bb + L[i], cc) + 10;
    int ans3 = solve(i + 1, aa, bb, cc + L[i]) + 10;
    return min({ ans0, ans1, ans2, ans3 });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B >> C;
    L.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    cout << solve(0, 0, 0, 0) << endl;

    return 0;
}
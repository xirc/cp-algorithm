#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B, int C, int X) {
    int ans = 0;
    for (int aa = 0; aa <= A; ++aa) {
        for (int bb = 0; bb <= B; ++bb) {
            for (int cc = 0; cc <= C; ++cc) {
                int xx = 500 * aa + 100 * bb + 50 * cc;
                if (xx == X) ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, X;
    cin >> A >> B >> C >> X;
    cout << solve(A, B, C, X) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int N, int Y) {
     for (int A = N; A >= 0; --A) {
        for (int B = N - A; B >= 0; --B) {
            int C = N - A - B;
            if (A * 10000 + B * 5000 + C * 1000 == Y) {
                return { A, B, C };
            }
        }
    }
    return { -1, -1, -1 };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Y;
    cin >> N >> Y;
    auto ans = solve(N, Y);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

    return 0;
}
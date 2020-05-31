#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans_s = 0, ans_w = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s, w;
        cin >> s >> w;
        if (s > w) {
            ans_s += 3;
        } else if (w > s) {
            ans_w += 3;
        } else {
            ans_s += 1;
            ans_w += 1;
        }
    }
    cout << ans_s << " " << ans_w << endl;

    return 0;
}
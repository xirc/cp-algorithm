#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    while (cin >> S, S != "-") {
        deque<char> buf(S.begin(), S.end());
        int M;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            int H;
            cin >> H;
            for (int j = 0; j < H; ++j) {
                char c = buf.front();
                buf.pop_front();
                buf.push_back(c);
            }
        }
        string ans(buf.begin(), buf.end());
        cout << ans << endl;
    }

    return 0;
}
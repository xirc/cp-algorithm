#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    const int N = S.size();

    int bw = 0;
    int wb = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2) {
            bw += S[i] == '1' ? 1 : 0;
            wb += S[i] == '0' ? 1 : 0;
        } else {
            bw += S[i] == '0' ? 1 : 0;
            wb += S[i] == '1' ? 1 : 0;
        }
    }
    cout << min(bw, wb) << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int solve(const string& bs, vector<int>& pos) {
    int K = 0;
    queue<int> zeros;
    queue<int> ones;

    pos.assign(bs.size(), 0);
    for (int i = 0; i < bs.size(); ++i) {
        if (bs[i] == '0') {
            if (ones.size() > 0) {
                int j = ones.front(); ones.pop();
                zeros.push(j);
                pos[i] = j;
            } else {
                zeros.push(K);
                pos[i] = K;
                ++K;
            }
        } else {
            if (zeros.size() > 0) {
                int j = zeros.front(); zeros.pop();
                ones.push(j);
                pos[i] = j;
            } else {
                ones.push(K);
                pos[i] = K;
                ++K;
            }
        }
    }
    return K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    string s;
    vector<int> pos;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        cin >> s;

        int ans = solve(s, pos);
        cout << ans << endl;
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << " ";
            cout << pos[j] + 1;
        }
        cout << endl;
    }

    return 0;
}
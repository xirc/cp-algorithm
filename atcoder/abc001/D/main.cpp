#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<vector<int>> A;

vector<vector<int>> solve() {
    vector<int> ts(24*60+2, 0);

    for (int i = 0; i < N; ++i) {
        int s = A[i][0], e = A[i][1];
        if (s % 5 > 0) s = s - s % 5;
        if (e % 5 > 0) e = e - e % 5 + 5;
        int ss = (s / 100) * 60 + (s % 100);
        int ee = (e / 100) * 60 + (e % 100);
        ts[ss] += 1;
        ts[ee] -= 1;
    }
    for (int i = 1; i < ts.size(); ++i) {
        ts[i] += ts[i-1];
    }

    vector<vector<int>> ans;
    int s = 0;
    bool rain = false;
    for (int t = 0; t < ts.size(); ++t) {
        if (!rain && ts[t] > 0) {
            s = t;
            rain = true;
        }
        if (rain && ts[t] == 0) {
            rain = false;
            int ss = (s / 60) * 100 + (s % 60);
            int ee = (t / 60) * 100 + (t % 60);
            ans.push_back({ ss, ee });
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string se;
        cin >> se;
        string s = se.substr(0, 4);
        string e = se.substr(5, 4);
        A.push_back({ stoi(s), stoi(e) });
    }

    auto ans = solve();
    for (int i = 0; i < ans.size(); ++i) {
        cout << setw(4) << setfill('0') << ans[i][0]
             << "-" << setw(4) << setfill('0') << ans[i][1] << endl;
    }

    return 0;
}
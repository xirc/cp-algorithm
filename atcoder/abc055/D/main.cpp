#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
string S;

bool solve(vector<char>& ws, char c0, char c1, char c2) {
    ws[0] = c1, ws[1] = c2, ws[N-1] = c0;
    for (int i = 1; i < N; ++i) {
        int j = (i - 1 + N) % N, k = (i + 1) % N;
        if (S[i] == 'o') {
            if (ws[i] == 'S') ws[k] = ws[j];
            if (ws[i] == 'W') ws[k] = ws[j] == 'S' ? 'W' : 'S';
        }
        if(S[i] == 'x') {
            if (ws[i] == 'S') ws[k] = ws[j] == 'S' ? 'W' : 'S';
            if (ws[i] == 'W') ws[k] = ws[j];
        }
    }
    bool satisfy = true;
    for (int i = 0; i < N; ++i) {
        int j = (i - 1 + N) % N, k = (i + 1) % N;
        if (S[i] == 'o') {
            if (ws[i] == 'S') satisfy &= (ws[k] == ws[j]);
            if (ws[i] == 'W') satisfy &= (ws[k] != ws[j]);
        }
        if (S[i] == 'x') {
            if (ws[i] == 'S') satisfy &= (ws[k] != ws[j]);
            if (ws[i] == 'W') satisfy &= (ws[k] == ws[j]);
        }
    }
    return satisfy;
}

vector<char> solve() {
    vector<char> ws(N, ' ');
    if (solve(ws, 'W', 'S', 'W')) return ws;
    if (solve(ws, 'S', 'S', 'S')) return ws;
    if (solve(ws, 'W', 'W', 'S')) return ws;
    if (solve(ws, 'S', 'W', 'W')) return ws;
    if (solve(ws, 'W', 'S', 'S')) return ws;
    if (solve(ws, 'S', 'S', 'W')) return ws;
    if (solve(ws, 'S', 'W', 'S')) return ws;
    if (solve(ws, 'W', 'W', 'W')) return ws;
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> S;
    auto ans = solve();
    cout << (ans.size() == 0 ? "-1" : string(ans.begin(), ans.end())) << endl;

    return 0;
}
// http://codeforces.com/contest/33/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e8;
int M;
string A, B;
vector<vector<int>> D(26, vector<int>(26, inf));

long long solve(string &ans) {
    if (A.size() != B.size()) {
        return -1;
    }

    for (int i = 0; i < 26; ++i) {
        D[i][i] = 0;
    }
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
    }

    long long answ = 0;
    vector<char> ansc;
    const int N = A.size();
    for (int i = 0; i < N; ++i) {
        if (A[i] == B[i]) {
            ansc.push_back(A[i]);
            continue;
        }
        int minw = inf;
        char minc = ' ';
        for (int j = 0; j < 26; ++j) {
            int w = D[A[i]-'a'][j] + D[B[i]-'a'][j];
            if (w < minw) {
                minw = w;
                minc = 'a' + j;
            }
        }
        if (minw == inf) {
            return -1;
        }
        answ += minw;
        ansc.push_back(minc);
    }

    ans = string(ansc.begin(), ansc.end());
    return answ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        char a, b; int c;
        cin >> a >> b >> c;
        D[a-'a'][b-'a'] = min(D[a-'a'][b-'a'], c);
    }

    string ans;
    auto w = solve(ans);
    cout << w << endl;
    if (w >= 0) {
        cout << ans << endl;
    }

    return 0;
}
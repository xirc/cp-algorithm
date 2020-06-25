#include <bits/stdc++.h>

using namespace std;

long long solve(const string& s) {
    const int N = s.size();
    int acc = 0;
    bool found_negative = false;
    vector<int> indice(N + 2, -1);
    for (int i = 0; i < N; ++i) {
        auto c = s[i];
        if (c == '+') {
            acc++;
        } else {
            acc--;
            if (acc < 0) {
                found_negative = true;
                if (indice[abs(acc)] == -1) {
                    indice[abs(acc)] = i;
                }
            }
        }
    }

    if (!found_negative) {
        return N;
    }
    long long ans = 0;
    for (int i = 0; i <= N; ++i) {
        if (indice[i+1] != -1) {
            ans += indice[i+1] + 1;
        } else {
            ans += N;
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
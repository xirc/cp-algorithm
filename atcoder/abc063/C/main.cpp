#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> S;

int solve() {
    int sum = 0;
    for (auto si : S) {
        sum += si;
    }
    if (sum % 10 != 0) {
        return sum;
    }

    bool found = false;
    int mini = 100;
    for (auto si : S) {
        if (si % 10 == 0) continue;
        found = true;
        mini = min(mini, si);
    }
    
    if (!found) {
        return 0;
    }
    return sum - mini;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}
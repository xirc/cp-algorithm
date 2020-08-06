#include <bits/stdc++.h>

using namespace std;

void dump(const vector<int>& bits, vector<int>& used) {
    int n = 0;
    for (int i = 0; i < bits.size(); ++i) {
        if (used[i]) {
            n += 1 << bits[i];
        }
    }
    cout << n << ":";
    for (int i = bits.size() - 1; i >= 0; --i) {
        if (used[i]) {
            cout << " " << bits[i];
        }
    }
    cout << endl;
}

void solve(const vector<int>& bits, vector<int>& used, int i) {
    if (i == bits.size()) {
        dump(bits, used);
        return;
    }
    solve(bits, used, i + 1);
    used[i] = true;
    solve(bits, used, i + 1);
    used[i] = false;
}
void solve(vector<int>& bits) {
    sort(bits.begin(), bits.end());
    reverse(bits.begin(), bits.end());

    vector<int> used(bits.size(), false);
    solve(bits, used, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<int> bits;

    cin >> N >> K;
    bits.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> bits[i];
    }
    solve(bits);

    return 0;
}
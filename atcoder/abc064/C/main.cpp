#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

vector<int> solve() {
    int K = 0;
    unordered_set<int> S;
    for (auto a : A) {
        if (a < 400) S.insert(0);
        else if (a < 800) S.insert(1);
        else if (a < 1200) S.insert(2);
        else if (a < 1600) S.insert(3);
        else if (a < 2000) S.insert(4);
        else if (a < 2400) S.insert(5);
        else if (a < 2800) S.insert(6);
        else if (a < 3200) S.insert(7);
        else ++K;
    }
    if (S.empty()) return { 1, K };
    return { (int)S.size(), (int)S.size() + K };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    auto minmax = solve();
    cout << minmax[0] << " " << minmax[1] << endl;

    return 0;
}
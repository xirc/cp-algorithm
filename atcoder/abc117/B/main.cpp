#include <bits/stdc++.h>

using namespace std;

bool solve(int N, vector<int> const& L) {
    int S = accumulate(L.begin(), L.end(), 0, plus<int>());
    int maxl = *max_element(L.begin(), L.end());
    return S - maxl > maxl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> L;
    cin >> N;
    L.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    cout << (solve(N,L) ? "Yes" : "No") << endl;

    return 0;
}
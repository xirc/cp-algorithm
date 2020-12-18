#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int solve() {
    map<int,int> M;
    for (auto ai : A) {
        ++M[ai];
    }
    int ans = 0;
    for (auto e : M) {
        auto v = e.first, c = e.second;
        if (v < c) {
            ans += (c - v);
        } else if (v > c) {
            ans += c;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}
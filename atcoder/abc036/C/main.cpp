#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &ai : A) cin >> ai;

    auto B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    auto mp = unordered_map<int,int>();
    for (int i = 0; i < (int)B.size(); ++i) {
        mp[B[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        cout << mp[A[i]] << endl;
    }

    return 0;
}
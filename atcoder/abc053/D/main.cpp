#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

int solve() {
    unordered_set<int> s;
    for (auto a : A) {
        s.insert(a);
    }
    int K = s.size();
    if (K % 2 == 0) return K - 1;
    else return K;
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
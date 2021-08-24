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
    for (auto &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    ll comfort = 0;
    priority_queue<int> Q;
    Q.push(A[0]);
    for (int i = 1; i < N; ++i) {
        auto c = Q.top(); Q.pop();
        comfort += c;
        Q.push(A[i]);
        Q.push(A[i]);
    }
    cout << comfort << endl;

    return 0;
}
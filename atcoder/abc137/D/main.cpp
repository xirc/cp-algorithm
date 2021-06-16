#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A, B;

int solve() {
    vector<array<int,2>> xs(N);
    for (int i = 0; i < N; ++i) {
        xs[i] = { A[i], B[i] };
    }
    sort(xs.begin(), xs.end());

    priority_queue<int> Q;
    int i = 0;
    int gain = 0;
    for (int time = 1; time <= M; ++time) {
        while (i < N && xs[i][0] <= time) {
            Q.push(xs[i][1]);
            ++i;
        }
        if (Q.size()) {
            gain += Q.top();
            Q.pop();
        }
    }
    return gain;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}
// https://atcoder.jp/contests/abc167/tasks/abc167_d

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
long long K;
vector<int> A;

vector<int> used;
vector<int> pred;
int find_cycle(int v) {
    used[v] = true;
    int u = A[v];
    pred[u] = v;
    if (used[u]) {
        return u;
    }
    return find_cycle(u);
}

int solve() {
    used.assign(N, false);
    pred.assign(N, -1);
    int s = find_cycle(0);

    auto count = K;
    int u = 0;
    for (; u != s && count > 0; u = A[u]) {
        count--;
    }
    if (count == 0) {
        return u;
    }

    vector<int> path;
    path.push_back(u);
    for (int v = A[u]; v != u; v = A[v]) {
        path.push_back(v);
    }
    if (path.size() == 0) {
        return u;
    }
    count %= path.size();
    int d = u;
    for (int i = 0; i < count; ++i) {
        d = A[d];
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i]--;
    }
    cout << solve() + 1 << endl;

    return 0;
}
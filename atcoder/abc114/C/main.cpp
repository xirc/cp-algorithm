#include <bits/stdc++.h>

using namespace std;

bool match(int v) {
    int n3 = 0, n5 = 0, n7 = 0;
    while (v > 0) {
        int d = v % 10;
        if (d == 3) ++n3;
        if (d == 5) ++n5;
        if (d == 7) ++n7;
        v /= 10;
    }
    return n3 > 0 && n5 > 0 && n7 > 0;
}

const int M = 1e8;
int solve(int N) {
    unordered_set<int> S;
    queue<int> Q;
    Q.push(0);

    while (Q.size()) {
        auto v = Q.front(); Q.pop();
        if (v > N) continue;
        if (match(v)) S.insert(v);
        if (v >= M) continue;
        Q.push(v * 10 + 3);
        Q.push(v * 10 + 5);
        Q.push(v * 10 + 7);
    }
    return S.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}
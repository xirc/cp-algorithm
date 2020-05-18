// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_5_B

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

using pii = pair<int,int>;

int N;
vector<pii> LT, RB;

const int S = 1001;
vector<vector<int>> A;
int solve() {
    A.assign(S, vector<int>(S, 0));
    for (int i = 0; i < N; ++i) {
        pii lt = LT[i], rb = RB[i];
        A[lt.first][lt.second]++;
        A[rb.first][rb.second]++;
        A[lt.first][rb.second]--;
        A[rb.first][lt.second]--;
    }

    for (int x = 1; x < S; ++x) {
        for (int y = 0; y < S; ++y) {
            A[x][y] += A[x-1][y];
        }
    }
    for (int y = 1; y < S; ++y) {
        for (int x = 0; x < S; ++x) {
            A[x][y] += A[x][y-1];
        }
    }
    int ans = 0;
    for (int x = 0; x < S; ++x) {
        for (int y = 0; y < S; ++y) {
            ans = max(ans, A[x][y]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    LT.assign(N, pii());
    RB.assign(N, pii());
    for (int i = 0; i < N; ++i) {
        cin >> LT[i].first >> LT[i].second;
        cin >> RB[i].first >> RB[i].second;
    }
    cout << solve() << endl;

    return 0;
}
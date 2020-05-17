// https://atcoder.jp/contests/abc168/tasks/abc168_c

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int A, B, H, M;

double solve() {
    double theta = (H * 60 + M) / (12.0 * 60) * 2 * M_PI;
    double x1 = A * sin(theta), y1 = A * cos(theta);
    double phi = M / 60.0 * 2 * M_PI;
    double x2 = B * sin(phi), y2 = B * cos(phi);
    double x3 = x2 - x1, y3 = y2 - y1;
    return hypot(x3, y3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> H >> M;
    cout << fixed << setprecision(9) << solve() << endl;

    return 0;
}
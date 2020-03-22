// https://atcoder.jp/contests/abc159/tasks/abc159_c

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double solve(int L) {
    return (L * L * L) / 27.0;
}

int main() {
    int L;
    cin >> L;
    cout << fixed << setprecision(7) << solve(L) << endl;
    return 0;
}
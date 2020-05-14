// https://atcoder.jp/contests/abc167/tasks/abc167_b

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, K;
    cin >> A >> B >> C >> K;

    if (K <= A) {
        cout << K << endl;
        return 0;
    }
    K -= A;
    if (K <= B) {
        cout << A << endl;
        return 0;
    }
    K -= B;
    cout << A - K << endl;

    return 0;
}
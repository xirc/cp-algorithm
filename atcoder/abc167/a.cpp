// https://atcoder.jp/contests/abc167/tasks/abc167_a

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;
    cin >> S >> T;
    auto U = T.substr(0, T.size()-1);
    if (S == U) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
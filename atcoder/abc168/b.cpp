// https://atcoder.jp/contests/abc168/tasks/abc168_b

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
    int K;
    string S;
    cin >> K >> S;

    if (S.size() <= K) {
        cout << S << endl;
    } else {
        string Q = S.substr(0, K) + "...";
        cout << Q << endl;
    }

    return 0;
}
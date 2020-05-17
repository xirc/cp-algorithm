// https://atcoder.jp/contests/abc168/tasks/abc168_a

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string solve(int N) {
    int dig = N % 10;
    switch (dig)
    {
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            return "hon";
        case 0:
        case 1:
        case 6:
        case 8:
            return "pon";
        case 3:
            return "bon";
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}
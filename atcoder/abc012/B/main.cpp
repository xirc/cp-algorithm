#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;
    int ss = N % 60;
    int mm = N / 60 % 60;
    int hh = N / 60 / 60;

    cout << setfill('0') << setw(2) << hh << ":";
    cout << setfill('0') << setw(2) << mm << ":";
    cout << setfill('0') << setw(2) << ss << endl;

    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
int solve1(int a, int b, int c) {
    if (a >= c) return -1;
    return 1;
}
int solve2(int a, int b, int c) {
    if (a >= c) return 2;
    if ((long long)a * b <= c) return -1;
    return floor((double)c / a) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve1(a, b, c) << " " << solve2(a, b, c) << endl;
    }
 
    return 0;
}